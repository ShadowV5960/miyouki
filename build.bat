@echo off
REM Vérifie qu'un argument est passé
IF "%1"=="" (
    echo Usage: build.bat nom_fichier_sans_extension
    exit /b 1
)

REM Compilation avec gcc
gcc %1.c geometrie.c interaction.c figure.c -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2 -o %1.exe

IF ERRORLEVEL 1 (
    echo Erreur de compilation
) ELSE (
    echo Compilation reussie: %1.exe genere
)
