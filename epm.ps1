param(
    [Parameter(Position=0)]
    [string]$Command,
    
    [Parameter(Position=1, ValueFromRemainingArguments=$true)]
    [string[]]$Args
)

$SCRIPT_DIR = Split-Path -Parent $MyInvocation.MyCommand.Path

switch ($Command) {
    "init" {
        if (Test-Path "equis.json") {
            Write-Error "[epm] Error: equis.json already exists in this directory."
            return
        }
        $name = Split-Path -Leaf (Get-Location)
        $json = @{
            name = $name
            version = "0.1.0"
            dependencies = @{}
        } | ConvertTo-Json
        $json | Out-File -FilePath "equis.json" -Encoding utf8
        
        if (-not (Test-Path "src")) { New-Item -ItemType Directory -Path "src" | Out-Null }
        if (-not (Test-Path "src/main.equis")) {
            "use `"std/sys.equis`";`n`nfn main() {`n    print_raw_str(`"Hello from Equis project: $name\n`");`n}`n`nmain();" | Out-File -FilePath "src/main.equis" -Encoding utf8
        }
        
        if (-not (Test-Path ".gitignore")) {
            "*.ll`n*.o`n*.exe`n.equis/" | Out-File -FilePath ".gitignore" -Encoding utf8
        }
        
        Write-Host "[epm] Initialized Equis project: $name" -ForegroundColor Green
    }

    "get" {
        if ($Args.Count -eq 0) {
            Write-Host "Usage: epm get <repo_url>" -ForegroundColor Yellow
            return
        }
        $repo = $Args[0]
        $name = [System.IO.Path]::GetFileNameWithoutExtension($repo)
        $pkgDir = Join-Path (Get-Location) ".equis\packages"
        if (-not (Test-Path $pkgDir)) { New-Item -ItemType Directory -Path $pkgDir -Force | Out-Null }
        
        $dest = Join-Path $pkgDir $name
        if (Test-Path $dest) {
            Write-Host "[epm] Updating $name..."
            Push-Location $dest
            & git pull
            Pop-Location
        } else {
            Write-Host "[epm] Fetching $name..."
            & git clone $repo $dest
        }

        # Update equis.json
        if (Test-Path "equis.json") {
            $config = Get-Content "equis.json" | ConvertFrom-Json
            if (-not $config.dependencies.$name) {
                $config.dependencies | Add-Member -MemberType NoteProperty -Name $name -Value $repo
                $config | ConvertTo-Json | Out-File -FilePath "equis.json" -Encoding utf8
            }
        }
        Write-Host "[epm] Package registered." -ForegroundColor Green
    }

    "install" {
        if (-not (Test-Path "equis.json")) {
            Write-Error "[epm] No equis.json found."
            return
        }
        $config = Get-Content "equis.json" | ConvertFrom-Json
        $deps = $config.dependencies
        if ($deps) {
            foreach ($name in $deps.psobject.Properties.Name) {
                $repo = $deps.$name
                Write-Host "[epm] Installing $name..."
                & $PSCommandPath get $repo
            }
        }
        Write-Host "[epm] All dependencies synchronized." -ForegroundColor Green
    }

    "run" {
        $eqPath = Join-Path $SCRIPT_DIR "eq.ps1"
        if (Test-Path $eqPath) {
            & powershell -File $eqPath run $Args
        } else {
            & eq run $Args
        }
    }

    default {
        Write-Host "Equis Package Manager (v0.1.0)" -ForegroundColor Cyan
        Write-Host "`nUsage: epm <command> [arguments]"
        Write-Host "`nCommands:"
        Write-Host "  init            - Scaffolds a new Equis project"
        Write-Host "  get <url>       - Installs and tracks a remote package"
        Write-Host "  install         - Restores all dependencies from equis.json"
        Write-Host "  run <file>      - Convenience wrapper for 'eq run'"
    }
}
