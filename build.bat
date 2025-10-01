@echo off
setlocal

rem Require g++
g++ --version >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo Error: g++ not found in PATH.
    exit /b 1
)

rem Ensure build directory exists
if not exist "build" mkdir "build"

rem Compile and print all diagnostics to the screen
g++ -std=c++17 -Wall -Wextra -g -DUNICODE -D_UNICODE -DWIN32_LEAN_AND_MEAN ^
    "KeyboardHook\KeyboardHook.cpp" -o "build\KeyboardHook.exe" -luser32 -lgdi32

rem Return with compiler’s exit code (0 = success, nonzero = failure)
exit /b %ERRORLEVEL%
