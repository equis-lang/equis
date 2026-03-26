$ErrorActionPreference = "Stop"

Write-Host "Bootstrapping Equis Core on Windows..." -ForegroundColor Cyan

Write-Host "Compiling eq-core.exe using gcc..."
& gcc -O3 bootstrap.c -o eq-core.exe -lws2_32
if ($LASTEXITCODE -ne 0) {
    Write-Host "Failed to compile eq-core.exe" -ForegroundColor Red
    exit 1
}

Write-Host "Generating compiler/main.ll from Main source..."
cmd /c ".\eq-core.exe -I std compiler/main.equis > compiler/main.ll"
if ($LASTEXITCODE -ne 0) {
    Write-Host "Failed to generate main.ll" -ForegroundColor Red
    exit 1
}

Write-Host "Patching main.ll IR structure (Domination Fix)..."
$ll = Get-Content compiler/main.ll
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
             # Fallback if no entry label found (shouldn't happen in Equis)
             Write-Host "Warning: No entry label in function, prepending allocas" -ForegroundColor Yellow
        }
        $inFunc = $false
    } elseif ($inFunc) {
        $funcBuffer.Add($line)
    } else {
        $output.Add($line)
    }
}
$final = $output -replace 'x86_64-pc-linux-gnu', 'x86_64-pc-win32-gnu'
$final | Set-Content compiler/main.ll -Encoding Ascii

Write-Host "Compiling compiler/main.exe from LLVM IR (targeting GNU/MinGW)..."
& clang -O3 -target x86_64-pc-windows-gnu -o compiler/main.exe compiler/main.ll compiler/runtime.c -lws2_32 -Wno-override-module
if ($LASTEXITCODE -ne 0) {
    Write-Host "Failed to compile main.exe" -ForegroundColor Red
    exit 1
}

Write-Host "Installing Stage-2 compiler as eq-core.exe..."
Move-Item compiler\main.exe eq-core.exe -Force

Write-Host "Bootstrap completed successfully." -ForegroundColor Green
exit 0
