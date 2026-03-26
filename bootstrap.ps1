$ErrorActionPreference = "Stop"

Write-Host "--- Equis Toolchain Bootstrap (Windows) ---" -ForegroundColor Cyan

Write-Host "`n[1/4] Compiling bootstrap core (GCC/MinGW)..." -ForegroundColor White
& gcc -O3 bootstrap.c -o eq-core.exe -lws2_32
if ($LASTEXITCODE -ne 0) {
    Write-Error "Bootstrap Phase 1 failed: GCC compilation error."
    exit 1
}

Write-Host "[2/4] Generating stage-2 LLVM IR..." -ForegroundColor White
cmd /c ".\eq-core.exe -I std compiler\main.equis > compiler\main.ll"
if ($LASTEXITCODE -ne 0) {
    Write-Error "Bootstrap Phase 2 failed: Compiler IR generation error."
    exit 1
}

Write-Host "[3/4] Applying IR structural patching (Domination Fix)..." -ForegroundColor White
$ll = Get-Content compiler\main.ll
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
    } else {
        $output.Add($line)
    }
}
$final = $output -replace 'x86_64-pc-linux-gnu', 'x86_128-pc-win32-gnu' # Ensuring Windows target
$final | Set-Content compiler\main.ll -Encoding Ascii

Write-Host "[4/4] Building production-grade stage-2 compiler (Clang)..." -ForegroundColor White
& clang -O3 -target x86_64-pc-windows-gnu -o compiler\main.exe compiler\main.ll compiler\runtime.c -lws2_32 -Wno-override-module
if ($LASTEXITCODE -ne 0) {
    Write-Error "Bootstrap Phase 4 failed: Clang compilation error."
    exit 1
}

Write-Host "`n[eq] Finalizing self-hosted executable..." -ForegroundColor Gray
if (Test-Path "eq-core.exe") { Remove-Item "eq-core.exe" -Force }
Move-Item compiler\main.exe eq-core.exe -Force

Write-Host "Bootstrap completed successfully." -ForegroundColor Green
