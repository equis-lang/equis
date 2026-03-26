param(
    [Parameter(Position=0)][string]$Command,
    [Parameter(Position=1, ValueFromRemainingArguments=$true)][string[]]$Args
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
    if (Test-Path (Join-Path $EQUIS_HOME "std")) { $EQUIS_STD = $EQUIS_HOME }
}
$INCLUDE_ARGS = @("-I", "$EQUIS_STD")
function Patch-IR($File, $Basename) {
    Write-Host "[eq] Patching IR for Windows compatibility..." -ForegroundColor Cyan
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
            $inFunc = $false
        } elseif ($inFunc) {
            $funcBuffer.Add($line)
        } else { $output.Add($line) }
    }
    $final = $output -replace 'x86_64-pc-linux-gnu', 'x86_64-pc-win32-gnu'
    $final | Set-Content "$Basename.ll" -Encoding Ascii
}
switch ($Command) {
    "compile" {
        $OutFile = ""; $InFile = ""
        for ($i=0; $i -lt $Args.Count; $i++) {
            if ($Args[$i] -eq "-o") { $OutFile = $Args[$i+1]; $i++ }
            else { $InFile = $Args[$i] }
        }
        if (-not $InFile) { Write-Host "Usage: eq compile <file.equis> [-o <output>]" -ForegroundColor Yellow; return }
        $Basename = [System.IO.Path]::GetFileNameWithoutExtension($InFile)
        if (-not $OutFile) { $OutFile = "$Basename.exe" }
        Write-Host "[eq] Generating LLVM IR..."
        & $EQUIS_CORE $INCLUDE_ARGS[0] $INCLUDE_ARGS[1] $InFile | Out-File -FilePath "$Basename.ll" -Encoding Ascii
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        Patch-IR $InFile $Basename
        Write-Host "[eq] Building native binary: $OutFile"
        & clang -O3 -o "$OutFile" "$Basename.ll" "$RUNTIME_C" -lws2_32 -Wno-override-tunit -target x86_64-pc-windows-gnu
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        Remove-Item "$Basename.ll"
        Write-Host "[eq] Compilation successful." -ForegroundColor Green
    }
    "run" {
        if (-not $Args) { Write-Host "Usage: eq run <file.equis>" -ForegroundColor Yellow; return }
        $File = $Args[0]
        $Basename = [System.IO.Path]::GetFileNameWithoutExtension($File)
        & $PSCommandPath compile "$File"
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        Write-Host "[eq] Executing..." -ForegroundColor Cyan
        & ".\$Basename.exe"
    }
    "check" {
        if (-not $Args) { Write-Host "Usage: eq check <file.equis>" -ForegroundColor Yellow; return }
        & $EQUIS_CORE $INCLUDE_ARGS[0] $INCLUDE_ARGS[1] --check $Args[0]
    }
    "lsp" { & $EQUIS_CORE $INCLUDE_ARGS[0] $INCLUDE_ARGS[1] --lsp }
    "build" {
        Write-Host "[eq] Rebuilding toolchain..." -ForegroundColor Cyan
        & $EQUIS_CORE $INCLUDE_ARGS compiler\main.equis | Out-File -FilePath "compiler\main.ll.new" -Encoding utf8
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        & clang -O3 -o compiler\eq-core.exe compiler\main.ll.new "$RUNTIME_C" -Wno-override-tunit
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        Remove-Item compiler\main.ll.new
        Write-Host "[eq] Toolchain synchronized." -ForegroundColor Green
    }
    "clean" {
        Remove-Item *.ll, *.o, *.exe -ErrorAction SilentlyContinue
        Write-Host "[eq] Workspace cleaned." -ForegroundColor Green
    }
    "version" { Write-Host "Equis Professional Toolchain v0.1.0 (Windows-Native)" -ForegroundColor Cyan }
    default {
        Write-Host "Equis Compiler Interface (v0.1.0)" -ForegroundColor Cyan
        Write-Host "`nUsage: eq <command> [arguments]"
        Write-Host "`nCommands:"
        Write-Host "  compile <file.equis>  - Generate optimized native binary"
        Write-Host "  run <file.equis>      - Compile and execute immediately"
        Write-Host "  check <file.equis>    - Perform semantic analysis only"
        Write-Host "  lsp                   - Launch Language Server Protocol"
        Write-Host "  build                 - Bootstrap local compiler core"
        Write-Host "  clean                 - Remove build artifacts from current directory"
        Write-Host "  version               - Display toolchain version"
    }
}
