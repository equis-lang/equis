

param(
    [Parameter(Position=0)]
    [string]$Command,
    
    [Parameter(Position=1, ValueFromRemainingArguments=$true)]
    [string[]]$Args
)


$EQUIS_BIN_DIR = $PSScriptRoot
if ($EQUIS_BIN_DIR.EndsWith("\bin")) {
    $EQUIS_HOME = Split-Path -Parent $EQUIS_BIN_DIR
    $EQUIS_LIB = Join-Path $EQUIS_HOME "lib"
    $EQUIS_CORE = Join-Path $EQUIS_LIB "eq-core.exe"
    if (-not (Test-Path $EQUIS_CORE)) { $EQUIS_CORE = Join-Path $EQUIS_LIB "eq-core" }
    $RUNTIME_C = Join-Path $EQUIS_LIB "runtime.c"
} else {
    $EQUIS_HOME = $EQUIS_BIN_DIR
    $EQUIS_LIB = $EQUIS_HOME
    $EQUIS_CORE = Join-Path $EQUIS_HOME "eq-core.exe"
    $RUNTIME_C = Join-Path $EQUIS_HOME "compiler\runtime.c"
}

$EQUIS_STD = $EQUIS_LIB
if (-not (Test-Path (Join-Path $EQUIS_STD "std"))) {
    if (Test-Path (Join-Path $EQUIS_HOME "std")) {
        $EQUIS_STD = $EQUIS_HOME
    }
}

$INCLUDE_ARGS = @("-I", "$EQUIS_STD")

switch ($Command) {
    "compile" {
        if (-not $Args) {
            Write-Host "Usage: eq compile <file.equis>" -ForegroundColor Yellow
            return
        }
        $File = $Args[0]
        $Basename = [System.IO.Path]::GetFileNameWithoutExtension($File)
        
        & $EQUIS_CORE $INCLUDE_ARGS[0] $INCLUDE_ARGS[1] $File | Out-File -FilePath "$Basename.ll" -Encoding Ascii
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        
        Write-Host "Patching IR structure..."
        $ll = Get-Content "$Basename.ll"
        $output = New-Object System.Collections.Generic.List[string]
        $funcBuffer = New-Object System.Collections.Generic.List[string]
        $inFunc = $false

        foreach ($line in $ll) {
            if ($line -match "^define ") {
                $inFunc = $true
                $funcBuffer.Clear()
                $funcBuffer.Add($line)
            } elseif ($line -match "^}") {
                $funcBuffer.Add($line)
                $processed = New-Object System.Collections.Generic.List[string]
                $fAllocas = New-Object System.Collections.Generic.List[string]
                foreach ($fLine in $funcBuffer) {
                    if ($fLine -match "=\s+alloca") { $fAllocas.Add($fLine) }
                    else { $processed.Add($fLine) }
                }
                $foundEntry = $false
                for ($i=0; $i -lt $processed.Count; $i++) {
                    $output.Add($processed[$i])
                    if ($processed[$i] -match "entry:") {
                        foreach ($a in $fAllocas) { $output.Add($a) }
                        $foundEntry = $true
                    }
                }
                if (-not $foundEntry -and $fAllocas.Count -gt 0) {
                    Write-Host "Warning: No entry block found for function in $File" -ForegroundColor Yellow
                }
                $inFunc = $false
            } elseif ($inFunc) {
                $funcBuffer.Add($line)
            } else {
                $output.Add($line)
            }
        }
        $final = $output -replace 'x86_64-pc-linux-gnu', 'x86_64-pc-win32-gnu'
        $final | Set-Content "$Basename.ll" -Encoding Ascii

        & clang -O3 -o "$Basename.exe" "$Basename.ll" "$RUNTIME_C" -lws2_32 -Wno-override-tunit -target x86_64-pc-windows-gnu
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        
        Remove-Item "$Basename.ll"
        Write-Host "Compiled: $Basename.exe" -ForegroundColor Green
    }
    
    "run" {
        if (-not $Args) {
            Write-Host "Usage: eq run <file.equis>" -ForegroundColor Yellow
            return
        }
        $File = $Args[0]
        $Basename = [System.IO.Path]::GetFileNameWithoutExtension($File)
        
        & $PSCommandPath compile "$File"
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        
        & ".\$Basename.exe"
    }
    
    "build" {
        Write-Host "Building Toolchain..." -ForegroundColor Cyan
        & $EQUIS_CORE $INCLUDE_ARGS compiler\main.equis | Out-File -FilePath "compiler\main.ll.new" -Encoding utf8
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        
        & clang -O3 -o compiler\eq-core.exe compiler\main.ll.new "$RUNTIME_C" -Wno-override-tunit
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        
        Remove-Item compiler\main.ll.new
        Write-Host "Build complete: compiler\eq-core.exe" -ForegroundColor Green
    }
    
    "version" {
        Write-Host "Equis Native Compiler v0.1.0 (Windows)" -ForegroundColor Cyan
    }
    
    default {
        Write-Host "Equis Wrapper (Windows)"
        Write-Host "Commands:"
        Write-Host "  compile <file.equis>  - Compile to native binary"
        Write-Host "  run <file.equis>      - Compile and run"
        Write-Host "  build                 - Rebuild the toolchain"
        Write-Host "  version               - Show version"
    }
}
