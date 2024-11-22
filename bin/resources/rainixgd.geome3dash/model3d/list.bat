@echo off
for /r %%f in (*) do (
    setlocal enabledelayedexpansion
    set "filepath=%%f"
    set "relative_path=!filepath:%cd%\=!"
    set "relative_path=!relative_path:\=/!"
    echo "resources/!relative_path!",
    endlocal
)

pause>nul