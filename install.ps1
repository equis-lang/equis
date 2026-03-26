$ErrorActionPreference = "Stop"
Write-Host "--------------------------------------------------------" -ForegroundColor Cyan
Write-Host "   Equis Professional Toolchain Installation (v0.1.0)   " -ForegroundColor Cyan
Write-Host "--------------------------------------------------------" -ForegroundColor Cyan
Write-Host "`n[1/3] Verifying system dependencies..." -ForegroundColor White
function Test-Dependency($name) {
    $found = Get-Command $name -ErrorAction SilentlyContinue
    return $null -ne $found
}
if (!(Test-Dependency "clang") -or !(Test-Dependency "make")) {
    Write-Host "[!] Missing dependencies (LLVM/MinGW). Attempting remediation..." -ForegroundColor Yellow
    if (!(Test-Dependency "winget")) { Write-Error "CRITICAL: 'winget' not found. Please install LLVM and GnuWin32 manually."; exit 1 }
    if (!(Test-Dependency "clang")) { Write-Host "Installing LLVM/Clang suite..."; winget install -e --id LLVM.LLVM }
    if (!(Test-Dependency "make")) { Write-Host "Installing GnuWin32/Make utility..."; winget install -e --id GnuWin32.Make }
    Write-Host "Dependencies successfully provisioned. Please restart your shell and re-run this script." -ForegroundColor Green
    exit 0
}
Write-Host "System dependencies verified." -ForegroundColor Gray
Write-Host "`n[2/3] Executing multi-stage bootstrap..." -ForegroundColor White
& .\bootstrap.ps1
if ($LASTEXITCODE -ne 0) { Write-Error "Bootstrap failed. Aborting installation."; exit 1 }
Write-Host "`n[3/3] Finalizing toolchain deployment..." -ForegroundColor White
$InstallDir = "$env:LOCALAPPDATA\Equis"
if (!(Test-Path $InstallDir)) { New-Item -ItemType Directory -Path $InstallDir -Force | Out-Null }
$ItemsToCopy = @("compiler", "std", "eq.ps1", "eq.bat", "epm.ps1", "epm.bat", "eq", "epm", "eq-core.exe")
foreach ($item in $ItemsToCopy) {
    if (Test-Path $item) { Copy-Item $item -Destination "$InstallDir\$item" -Recurse -Force }
}
$UserPath = [Environment]::GetEnvironmentVariable("Path", "User")
if ($UserPath -notlike "*$InstallDir*") {
    Write-Host "Configuring persistent environment variables..." -ForegroundColor Gray
    [Environment]::SetEnvironmentVariable("Path", "$UserPath;$InstallDir", "User")
}
Write-Host "`n--------------------------------------------------------" -ForegroundColor Green
Write-Host " SUCCESS: Equis v0.1.0 Toolchain is now operational." -ForegroundColor Green
Write-Host " Use 'eq' for the compiler and 'epm' for package management."
Write-Host "--------------------------------------------------------" -ForegroundColor Green
