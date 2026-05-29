@echo off
echo "TSAAGPM C Architecture x64 DLL Build"
mkdir build

set "MSVC_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build"

call "%MSVC_PATH%\vcvarsall.bat" amd64

cl /LD architecture.c -o build\architectureC.dll > build\build_arch64_log.txt

timeout /t 15