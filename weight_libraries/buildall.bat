@echo off
setlocal

rem — adjust this to point at your source root
set "SRC=%~dp0"

rem list of “Generator;Architecture” pairs
set GENERATORS=^
  "Visual Studio 16 2019;Win32" ^
  "Visual Studio 17 2022;x64"

rem  "Visual Studio 17 2022;Win32"
rem  "Visual Studio 16 2019;x64"

rem iterate over each generator/arch combo
for %%G in (%GENERATORS%) do (
  echo "GENERATOR=%%G"
  for /f "tokens=1,2 delims=;" %%A in ("%%~G") do (
    set "GEN=%%A"
    set "ARCH=%%B"

    rem build both Debug and Release
    for %%C in (Debug Release) do (
      set "CFG=%%C"
      set "BUILD_DIR=build\%%A\%%B\%%C"
      
      echo ================================
      echo Configuring %GEN% / %ARCH% / %CFG%
      echo ================================
      cmake -S "%SRC%" -B "%BUILD_DIR%" ^
        -G "%GEN%" -A "%ARCH%" ^
        -DCMAKE_CONFIGURATION_TYPES="Debug;Release" > "%BUILD_DIR%\cmake_configure.log" 2>&1

      echo Building %GEN% / %ARCH% / %CFG%
      cmake --build "%BUILD_DIR%" --config "%CFG%" ^
        > "%BUILD_DIR%\cmake_build_%CFG%.log" 2>&1
    )
  )
)

endlocal
echo All done!
pause
