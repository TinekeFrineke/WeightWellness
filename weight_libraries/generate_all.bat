@echo off
setlocal

rem Paths
set ROOT_DIR=%~dp0
set BUILD_DIR_VS2019=%ROOT_DIR%build/vs2019
set BUILD_DIR_VS2022=%ROOT_DIR%build/vs2022

rem VS2019 Win32
cmake -S %ROOT_DIR% -B %BUILD_DIR_VS2019%/x86 -G "Visual Studio 16 2019" -A Win32

rem VS2019 x64
cmake -S %ROOT_DIR% -B %BUILD_DIR_VS2019%/x64 -G "Visual Studio 16 2019" -A x64

rem VS2022 Win32
cmake -S %ROOT_DIR% -B %BUILD_DIR_VS2022%/x86 -G "Visual Studio 17 2022" -A Win32

rem VS2022 x64
cmake -S %ROOT_DIR% -B %BUILD_DIR_VS2022%/x64 -G "Visual Studio 17 2022" -A x64

echo Done generating all solutions.
pause