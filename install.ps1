

$ErrorActionPreference = "Stop"

Write-Host "--------------------------------------------------" -ForegroundColor Cyan
Write-Host "   Equis Compiler Installation Script (v0.1.0)    " -ForegroundColor Cyan
Write-Host "--------------------------------------------------" -ForegroundColor Cyan


Write-Host "[1/3] Resolving dependencies..."

function Check-Dependency($name) {
    $found = Get-Command $name -ErrorAction SilentlyContinue
    return $found -ne $null
}

if (!(Check-Dependency "clang") -or !(Check-Dependency "make")) {
    Write-Host "Missing dependencies (LLVM/Clang or Make) found. Attempting installation via Winget..." -ForegroundColor Yellow
    

    if (!(Check-Dependency "winget")) {
        Write-Host "Error: 'winget' not found. Please install LLVM (Clang) and GnuWin32 (Make) manually." -ForegroundColor Red
        exit 1
    }

    if (!(Check-Dependency "clang")) {
        Write-Host "Installing LLVM..."
        winget install -e --id LLVM.LLVM
    }

    if (!(Check-Dependency "make")) {
        Write-Host "Installing Make..."
        winget install -e --id GnuWin32.Make
    }

    Write-Host "Dependencies installed. Please restart your terminal and run this script again." -ForegroundColor Green
    exit 0
}

Write-Host "Dependencies verified."


Write-Host "[2/3] Building Equis compiler (Bootstrapping)..."

& .\bootstrap.ps1
if ($LASTEXITCODE -ne 0) {
    Write-Host "Bootstrap failed." -ForegroundColor Red
    exit 1
}


Write-Host "[3/3] Finalizing installation..."
$InstallDir = "$env:LOCALAPPDATA\Equis"

if (!(Test-Path $InstallDir)) {
    New-Item -ItemType Directory -Path $InstallDir -Force | Out-Null
}

Copy-Item "compiler" -Destination "$InstallDir\compiler" -Recurse -Force
Copy-Item "eq.ps1" -Destination "$InstallDir\eq.ps1" -Force
Copy-Item "eq" -Destination "$InstallDir\eq" -Force


$UserPath = [Environment]::GetEnvironmentVariable("Path", "User")
if ($UserPath -notlike "*$InstallDir*") {
    Write-Host "Adding Equis to Path..."
    [Environment]::SetEnvironmentVariable("Path", "$UserPath;$InstallDir", "User")
}

Write-Host "--------------------------------------------------" -ForegroundColor Green
Write-Host "SUCCESS: Equis v0.1.0 installed successfully." -ForegroundColor Green
Write-Host "You can now use the 'eq' command." -ForegroundColor Green
Write-Host "--------------------------------------------------" -ForegroundColor Green
