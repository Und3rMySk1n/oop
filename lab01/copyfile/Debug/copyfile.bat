REM Program start without parameters
copyfile.exe 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with one parameter
copyfile.exe text.txt 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with two parameters (First file is empty)
copyfile.exe empty.txt output.txt 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with 3 parameters
copyfile.exe input.txt output.txt third.txt 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with two parameters (First file is not empty)
copyfile.exe input.txt output.txt 
IF ERRORLEVEL 1 GOTO err

FC input.txt output.txt 
IF ERRORLEVEL 1 GOTO err

ECHO Success
EXIT

:err 
ECHO Failed
EXIT