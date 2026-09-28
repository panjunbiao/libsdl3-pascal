# Download the pinned official Win64 SDL DLLs into the example folders.
# Binaries stay out of git. They come from the GitHub release assets.
param(
    [string]$Dest
)

$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12

$RepoRoot = Split-Path -Parent $PSScriptRoot
$Cache = Join-Path $RepoRoot '.cache\dlls'
New-Item -ItemType Directory -Force -Path $Cache | Out-Null
Add-Type -AssemblyName System.IO.Compression.FileSystem

$Core = @{
    Url = 'https://github.com/libsdl-org/SDL/releases/download/release-3.4.16/SDL3-3.4.16-win32-x64.zip'
    Zip = 'SDL3-3.4.16-win32-x64.zip'
    License = 'LICENSE.SDL3.txt'
    Names = @('SDL3.dll')
}
$Satellites = @(
    @{
        Url = 'https://github.com/libsdl-org/SDL_image/releases/download/release-3.4.4/SDL3_image-3.4.4-win32-x64.zip'
        Zip = 'SDL3_image-3.4.4-win32-x64.zip'
        License = 'LICENSE.SDL3_image.txt'
        Names = @('SDL3_image.dll')
        Optional = $true
    },
    @{
        Url = 'https://github.com/libsdl-org/SDL_ttf/releases/download/release-3.2.2/SDL3_ttf-3.2.2-win32-x64.zip'
        Zip = 'SDL3_ttf-3.2.2-win32-x64.zip'
        License = 'LICENSE.SDL3_ttf.txt'
        Names = @('SDL3_ttf.dll')
        Optional = $false
    },
    @{
        Url = 'https://github.com/libsdl-org/SDL_mixer/releases/download/release-3.2.4/SDL3_mixer-3.2.4-win32-x64.zip'
        Zip = 'SDL3_mixer-3.2.4-win32-x64.zip'
        License = 'LICENSE.SDL3_mixer.txt'
        Names = @('SDL3_mixer.dll')
        Optional = $true
    }
)

function Get-OfficialZip($Pin) {
    $path = Join-Path $Cache $Pin.Zip
    if (-not (Test-Path -LiteralPath $path)) {
        Write-Host "Downloading $($Pin.Url)"
        Invoke-WebRequest -Uri $Pin.Url -OutFile $path -UseBasicParsing
    }
    return $path
}

function Copy-ZipEntry($Entry, $DestPath) {
    $parent = Split-Path -Parent $DestPath
    if ($parent) {
        New-Item -ItemType Directory -Force -Path $parent | Out-Null
    }
    [System.IO.Compression.ZipFileExtensions]::ExtractToFile($Entry, $DestPath, $true)
}

function Copy-Pin($Pin, $DestDir, [switch]$IncludeLicense) {
    $zipPath = Get-OfficialZip $Pin
    $zip = [System.IO.Compression.ZipFile]::OpenRead($zipPath)
    $wanted = New-Object System.Collections.Generic.List[string]
    foreach ($name in $Pin.Names) { [void]$wanted.Add($name) }
    $found = @{}
    try {
        foreach ($entry in $zip.Entries) {
            if ([string]::IsNullOrEmpty($entry.Name)) { continue }
            $rel = $entry.FullName.Replace('\', '/')
            $isOptional = $rel -match '(^|/)optional/.+\.dll$'
            $take = $false
            if ($wanted.Contains($entry.Name) -and -not $isOptional) { $take = $true }
            if ($Pin.Optional -and $isOptional) { $take = $true }
            if ($take) {
                $destPath = Join-Path $DestDir $entry.Name
                Copy-ZipEntry $entry $destPath
                $found[$entry.Name] = $true
                Write-Host "  $($entry.Name) -> $DestDir"
            } elseif ($IncludeLicense -and $entry.Name -eq 'LICENSE.txt') {
                Copy-ZipEntry $entry (Join-Path $DestDir $Pin.License)
            }
        }
    } finally {
        $zip.Dispose()
    }
    foreach ($name in $Pin.Names) {
        if (-not $found.ContainsKey($name)) {
            throw "Did not find $name in $($Pin.Zip)"
        }
    }
}

function Assert-Win64Dll($Path) {
    $fs = [System.IO.File]::OpenRead($Path)
    try {
        $br = New-Object System.IO.BinaryReader($fs)
        $fs.Position = 0x3C
        $pe = $br.ReadInt32()
        $fs.Position = $pe + 4
        $machine = $br.ReadUInt16()
        if ($machine -ne 0x8664) {
            throw "$Path is not a Win64 DLL (machine 0x$($machine.ToString('X')))"
        }
    } finally {
        $fs.Dispose()
    }
}

function Get-Targets($ExampleDir) {
    $targets = @($ExampleDir)
    foreach ($cfg in @('Debug', 'Release')) {
        $built = Join-Path $ExampleDir "Win64\$cfg"
        if (Test-Path -LiteralPath $built) { $targets += $built }
    }
    return $targets
}

if ($Dest) {
    New-Item -ItemType Directory -Force -Path $Dest | Out-Null
    Copy-Pin $Core $Dest -IncludeLicense
    foreach ($pin in $Satellites) { Copy-Pin $pin $Dest -IncludeLicense }
    Assert-Win64Dll (Join-Path $Dest 'SDL3.dll')
    Write-Host "Official DLLs are in $Dest"
    return
}

$examples = Get-ChildItem -LiteralPath (Join-Path $RepoRoot 'examples') -Directory
foreach ($example in $examples) {
    $dpr = Get-ChildItem -LiteralPath $example.FullName -Filter '*.dpr' -File | Select-Object -First 1
    if (-not $dpr) { continue }
    foreach ($target in (Get-Targets $example.FullName)) {
        Copy-Pin $Core $target
        if ($example.Name -eq 'satellites') {
            foreach ($pin in $Satellites) { Copy-Pin $pin $target }
        }
        Assert-Win64Dll (Join-Path $target 'SDL3.dll')
    }
}

Write-Host "Official DLLs are next to each example. satellites also has SDL3_image, SDL3_ttf, SDL3_mixer, and their optional decoders."
