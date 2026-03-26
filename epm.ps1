

Param(
    [Parameter(Position=0, Mandatory=$true)]
    [String]$Command,
    
    [Parameter(ValueFromRemainingArguments=$true)]
    [String[]]$RemainingArgs
)

$SCRIPT_DIR = Split-Path -Parent $MyInvocation.MyCommand.Path

switch ($Command) {
    "init" {
        $name = Split-Path -Leaf (Get-Location)
        $json = @{
            name = $name
            version = "0.1.0"
            dependencies = @{}
        } | ConvertTo-Json
        $json | Out-File -FilePath "equis.json" -Encoding utf8
        Write-Host "Initialized equis.json"
    }
    "get" {
        if ($RemainingArgs.Count -eq 0) {
            Write-Error "Usage: epm get <repo_url>"
            exit 1
        }
        $repo = $RemainingArgs[0]
        $name = [System.IO.Path]::GetFileNameWithoutExtension($repo)
        $pkgDir = Join-Path (Get-Location) ".equis\packages"
        if (-not (Test-Path $pkgDir)) { New-Item -ItemType Directory -Path $pkgDir | Out-Null }
        
        $dest = Join-Path $pkgDir $name
        if (Test-Path $dest) {
            Push-Location $dest
            git pull
            Pop-Location
        } else {
            git clone $repo $dest
        }
        Write-Host "Package $name installed to $dest"
    }
    "run" {
        $eqPath = Join-Path $SCRIPT_DIR "eq.ps1"
        if (Test-Path $eqPath) {
            & powershell -File $eqPath run @RemainingArgs
        } else {

            eq run @RemainingArgs
        }
    }
    Default {
        Write-Host "Usage: epm [init|get|run]"
        exit 1
    }
}
