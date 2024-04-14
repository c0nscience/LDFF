function Remove-Folder($path, $folder) {
    $pathToDelete = Join-Path $path $folder
    if (Test-Path $pathToDelete -PathType Leaf) {
        $fullPath = (Resolve-Path $pathToDelete).ProviderPath
        Write-Host "Remove file $fullPath"
        Remove-Item -Force $fullPath
    } elseif(Test-Path $pathToDelete -PathType Container) {
        $fullPath = (Resolve-Path $pathToDelete).ProviderPath
        Write-Host "Remove folder pathToDelete $pathToDelete"
        Write-Host "Remove folder fullPath $fullPath"
        [IO.Directory]::Delete("$fullPath", $true) | Out-Null   
    }
}

function Remove-Generate-Files($path) {
    Write-Host "Remove generated files from $path"
    @('.vs', '.idea', 'Binaries', 'Build', 'DerivedDataCache', 'Intermediate', 'Saved', '*.sln').ForEach({ 
        Remove-Folder -path $path -folder $_ 
    })
}

function Reset-Project($projectName) {
    $ProjectFolder = $PSScriptRoot
    $ProjectFile = Join-Path $ProjectFolder "$projectName.uproject"

    Remove-Generate-Files $ProjectFolder
}

Reset-Project "LDFF"
