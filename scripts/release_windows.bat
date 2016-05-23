@ECHO OFF
ECHO ###########################
ECHO  Make release version of
ECHO  Genek with one click
ECHO  Needs UPX, OptiPNG and
ECHO  CBP2MAKE but it will
ECHO  work anyway, without
ECHO  these features.
ECHO  by pajadam
ECHO ###########################
ECHO - Generating updated
ECHO   makefile from CBP project
cbp2make -in Genek.cbp -out makefile -targets "Windows" >nul
ECHO - Packing Genek.exe
upx -q -9 bin\Windows\Genek.exe >nul
ECHO - Creating release directory
rd /s /q release >nul
mkdir "release" >nul
mkdir "release\data" >nul
ECHO - Moving needed objects to
ECHO   release folder
copy "bin\Windows\Genek.exe" "release\" >nul
xcopy "data" "release\data\" /s /e /y /i >nul
ECHO Check out release folder
ECHO DONE :D
ECHO ###########################
GOTO :EOF

