@echo off
REM === Argument validation ===
if "%~3"=="" (
    echo [!] Usage: compile-cs.bat [source_abs] [temp_abs] [relative_file]
    pause
    exit /b 1
)

set "SOURCE=%~1"
set "TEMPROOT=%~2"
set "RELFILE=%~3"

for %%I in ("%SOURCE%") do set "FILENAME=%%~nI"
set "RELFILE=%RELFILE:/=/%"

REM === Set output extension based on DEBUG ===
set "EXT=.exe"
if "%DEBUG%"=="1" (
    set "EXT=.debug.exe"
)

set "OUTFILE=%TEMPROOT%/%RELFILE:.cs=%%EXT%"
for %%I in ("%OUTFILE%") do set "OUTDIR=%%~dpI"

echo ----------------------------------------
echo            Compilation Info
echo ----------------------------------------
echo SOURCE       : %SOURCE%
echo TEMP ROOT    : %TEMPROOT%
echo RELATIVE     : %RELFILE%
echo FILENAME     : %FILENAME%
echo OUTPUT DIR   : %OUTDIR%
echo EXECUTABLE   : %OUTFILE%
echo.

REM === Check if the process is already running ===
tasklist /FI "IMAGENAME eq %FILENAME%%EXT%" | find /I "%FILENAME%%EXT%" >nul
if %errorlevel%==0 (
    echo [ERROR] %FILENAME%%EXT% is already running.
    pause
    exit /b 1
)

REM === Clean up previous build ===
if exist "%OUTDIR%" (
    echo [CLEAN] Removing: %OUTDIR%
    rmdir /s /q "%OUTDIR%"
)

mkdir "%OUTDIR%" >nul 2>nul

REM === Set compile flags ===
set "COMPILER_FLAGS="
if "%DEBUG%"=="1" (
    set "COMPILER_FLAGS=/debug"
)

echo [BUILD] csc %COMPILER_FLAGS% /out:"%OUTFILE%" "%SOURCE%"
csc %COMPILER_FLAGS% /out:"%OUTFILE%" "%SOURCE%"
set "COMPILATION_SUCCESS=%errorlevel%"

REM === Handle compile result ===
if NOT "%COMPILATION_SUCCESS%"=="0" (
    echo [FAIL] Compilation failed.
    if exist "%OUTFILE%" del /f /q "%OUTFILE%"
    pause
    exit /b 1
)

echo [OK] Compilation succeeded.
exit /b 0