REM Program start without parameters
invert.exe 
IF NOT ERRORLEVEL 1 GOTO err

REM Program start with right matrix on input
invert.exe matrix.txt 
IF ERRORLEVEL 1 GOTO err

REM Program start with wrong matrix on input (determinant == 0)
invert.exe matrix_2.txt
IF NOT ERRORLEVEL 1 GOTO err
                 
REM Check result for right matrix
invert.exe matrix.txt > result_matrix.txt
FC result_matrix.txt output_example.txt 
IF ERRORLEVEL 1 GOTO err

ECHO Success
EXIT

:err 
ECHO Failed
EXIT