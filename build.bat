rem @echo off

REM Determine Houdini root
if NOT DEFINED HOUDINI_ROOT (
    set "HOUDINI_ROOT=C:\Program Files\Side Effects Software\Houdini 16.5.268"
)

REM Determine muted assets workspaces root
if NOT DEFINED MUTED_ASSETS_WORKSPACE_ROOT (
    set "MUTED_ASSETS_WORKSPACE_ROOT=%~dp0\..\..\"
)

REM Determine MSVCDir
if NOT DEFINED MSVCDir (
    set "MSVCDir=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build"
    REM set "MSVCDir=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC"
)

cd /D "%MSVCDir%"
call vcvars64.bat

cd /D "%MUTED_ASSETS_WORKSPACE_ROOT%\Tools\HoudiniFBX"
mkdir build
cd /D build

cmake -G "Visual Studio 15 2017" -T "v141" -A "x64" -DHOUDINI_ROOT="%HOUDINI_ROOT%" -DMUTED_ASSETS_WORKSPACE_ROOT="%MUTED_ASSETS_WORKSPACE_ROOT%" ..\

rem cmake -G "Visual Studio 15 2017" -A "x64" -DHOUDINI_ROOT="%HOUDINI_ROOT%" -DMUTED_ASSETS_WORKSPACE_ROOT="%MUTED_ASSETS_WORKSPACE_ROOT%" ..\

cd /D "%MUTED_ASSETS_WORKSPACE_ROOT%\Tools\HoudiniFBX\build"

REM msbuild ROP_FBX.sln /p:Configuration=Release /t:Build
msbuild ROP_FBX.sln /p:PlatformToolset=v141 /p:Configuration=Release /t:Build

pause