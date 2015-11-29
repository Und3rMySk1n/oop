REM Program start without parameters
flipbyte.exe 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with one parameter (<0)
flipbyte.exe -1 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with two parameters (>255)
flipbyte.exe 256 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with letters in command line
flipbyte.exe sda 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with letters and numbers in command line
flipbyte.exe 6s 
IF NOT ERRORLEVEL 1 GOTO err

REM Check result for 6 (must be 96)
flipbyte.exe 6 > result.txt
FC result.txt 96.txt 
IF ERRORLEVEL 1 GOTO err

ECHO Success
EXIT

:err 
ECHO Failed
EXIT