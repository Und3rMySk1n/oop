#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "MatrixUtils.h"

using namespace std;
// именование функций - UpperCamelCase
// разбить InvertMatrix на несколько функций
// SingleOneMatrix - переименовать в IdentityMatrix
// Вместо вектора использовать двумерный массив
// Если матрица не изменяется в функции - передавать ее по константной ссылке
// Задать typedef'ы для матриц
// Функцию распечатки матрицы - сделать менее универсальной, не передавать размер


enum status
{
	OK, INPUT_FILE_NOT_OPENED, READ_ERROR, DETERMINANT_ZERO
};

void printError(status &statusCode)
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

bool invertMatrix(const string &inputFileName, status &statusCode)
{
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		statusCode = INPUT_FILE_NOT_OPENED;
		return false;
	}

	vector<vector<int>> matrix(3, vector<int>(3));
	vector<vector<int>> singleOneMatrix(3, vector<int>(3));	
	defineSingleOneMatrix(singleOneMatrix, 3);	
	
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

	int determinant = FindDeterminantForMatrix_3x3(matrix);
	if (determinant == 0)
	{
		statusCode = DETERMINANT_ZERO;
		return false;
	}
	else
	{
		vector<vector<double>> inverseMatrix(3, vector<double>(3));
		inverseMatrix = FindInverseMatrix_3x3(matrix, determinant);

		printSquareMatrixTypeDouble(inverseMatrix, 3);
		cout << endl;
	}

	return true;
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

	status statusCode = OK;
	if (!invertMatrix(argv[1], statusCode))
	{
		printError(statusCode);
		return 1;
	}

	return 0;
}