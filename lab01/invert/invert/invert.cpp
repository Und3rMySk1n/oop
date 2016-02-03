#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "MatrixUtils.h"

using namespace std;
// именование функций - UpperCamelCase +
// разбить InvertMatrix на несколько функций +
// SingleOneMatrix - переименовать в IdentityMatrix +
// Вместо вектора использовать двумерный массив +
// Если матрица не изменяется в функции - передавать ее по константной ссылке +
// Задать typedef'ы для матриц +
// Функцию распечатки матрицы - сделать менее универсальной, не передавать размер +


enum status
{
	OK, INPUT_FILE_NOT_OPENED, READ_ERROR, DETERMINANT_ZERO
};

void PrintError(status &statusCode)
{
	switch (statusCode)
	{
	    case INPUT_FILE_NOT_OPENED:
	    {
		    cout << "File open failed." << endl;
		    break;
	    }
	    case READ_ERROR:
	    {
		    cout << "File reading error." << endl;
	    }
		case DETERMINANT_ZERO:
		{
			cout << "Wrong matrix. Determinant is 0." << endl;
		}
	}
}

bool OpenInputFile(const string &inputFileName, ifstream &inputFile, status &statusCode)
{
	inputFile.open(inputFileName, ifstream::in);
	if (!inputFile.is_open())
	{
		statusCode = INPUT_FILE_NOT_OPENED;
		return false;
	}

	return true;
}

matrix33 ReadMatrixFromFile(ifstream &inputFile)
{	
	matrix33 matrix;

	while (!inputFile.eof())
	{
		char letter;
		for (int i = 0; i < 3; i++)
		{
			letter = inputFile.get();
			while ((letter != '\n') && (!inputFile.eof()))
			{				
				for (int j = 0; j < 3; j++)
				{
					string numberToParse = "";					
					while ((letter != ' ') && (letter != '\n') && (!inputFile.eof()))
					{						
						numberToParse = numberToParse + letter;
						letter = inputFile.get();					
					}

					char *stringPtr = &numberToParse[0];
					matrix[i][j] = stoi(stringPtr, NULL, 10);					

					if ((letter != '\n') && (!inputFile.eof()))
					{
						while (letter == ' ')
						{
							letter = inputFile.get();
						}						
					}									
				}
			}
		}
	}		

	return matrix;
}

matrix33 GetInvertMatrix(matrix33 &matrix, status &statusCode)
{
	matrix33 inverseMatrix;
	double determinant = FindDeterminantForMatrix_3x3(matrix);
	if (determinant == 0)
	{
		statusCode = DETERMINANT_ZERO;
	}
	else
	{		
		inverseMatrix = FindInverseMatrix_3x3(matrix, determinant);		
	}

	return inverseMatrix;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "You should enter a text file with input matrix." << endl;
		return 1;
	}
	else
	{
		cout << "This program inverts input matrix." << endl;
	}

	ifstream inputFile;
	status statusCode = OK;
	if (!OpenInputFile(argv[1], inputFile, statusCode))
	{
		PrintError(statusCode);
		return 1;
	}

	matrix33 matrix = ReadMatrixFromFile(inputFile);
	matrix33 inverseMatrix = GetInvertMatrix(matrix, statusCode);

	if (statusCode != DETERMINANT_ZERO)
	{
		PrintSquareMatrix_3x3(inverseMatrix);
		cout << endl;
	}
	else
	{
		PrintError(statusCode);
		return 1;
	}	

	return 0;
}