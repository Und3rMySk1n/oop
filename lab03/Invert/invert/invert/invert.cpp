#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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

void printSquareMatrix(vector<vector<int>> &matrixToPrint, const int &matrixSize)
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << "[" << i << "][" << j << "] = " << matrixToPrint[i][j] << " ";
		}
		cout << endl;
	}
}

void printSquareMatrixTypeDouble(vector<vector<double>> &matrixToPrint, const int &matrixSize)
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cout << setprecision(3) << matrixToPrint[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

int FindDeterminantForMatrixTwoOnTwo(vector<vector<int>> &matrixTwoOnTwo)
{
	int determinant = (matrixTwoOnTwo[0][0] * matrixTwoOnTwo[1][1]) -
		(matrixTwoOnTwo[0][1] * matrixTwoOnTwo[1][0]);

	return determinant;
}

vector<vector<int>> FindRestOfMatrix(vector<vector<int>> &matrixToFindRest, int matrixSize, int thisString, int thisColumn)
{
	int restMatrixSize = matrixSize - 1;
	vector<vector<int>> restMatrix(restMatrixSize, vector<int>(restMatrixSize));
	int m = 0;
	int n = 0;

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if ((i != thisString) && (j != thisColumn))
			{
				if (m == restMatrixSize)
				{
					cout << "Matrix overflow." << endl;
					break;
				}

				restMatrix[m][n] = matrixToFindRest[i][j];
				n++;
				if (n == restMatrixSize)
				{
					n = 0;
					m++;
				}
			}
		}
	}

	return restMatrix;
}

int FindDeterminantForMatrixThreeOnThree(vector<vector<int>> &matrixThreeOnThree)
{
	int determinant = 0;
	int thisString = 0; //Ќаходим детерминант по первой строке
	int summarySign = 1;

	for (int thisColumn = 0; thisColumn < 3; thisColumn++)
	{
		vector<vector<int>> matrixTwoOnTwo(2, vector<int>(2));
		matrixTwoOnTwo = FindRestOfMatrix(matrixThreeOnThree, 3, thisString, thisColumn);

		determinant += matrixThreeOnThree[thisString][thisColumn] * FindDeterminantForMatrixTwoOnTwo(matrixTwoOnTwo) * summarySign;
		summarySign = summarySign * (-1);
	}

	return determinant;
}

void defineSingleOneMatrix(vector<vector<int>> &matrixToDefine, const int &matrixSize)
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (i == j)
			{
				matrixToDefine[i][j] = 1;
			}
			else
			{
				matrixToDefine[i][j] = 0;
			}
		}
	}
}

vector<vector<int>> FindMinorMatrix(vector<vector<int>> &matrixToFindMinor, const int &matrixSize)
{
	int smallMatrixSize = matrixSize - 1;
	vector<vector<int>> smallMatrix(smallMatrixSize, vector<int>(smallMatrixSize));
	vector<vector<int>> minorMatrix(matrixSize, vector<int>(matrixSize));

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			smallMatrix = FindRestOfMatrix(matrixToFindMinor, matrixSize, i, j);
			minorMatrix[i][j] = FindDeterminantForMatrixTwoOnTwo(smallMatrix);
		}
	}

	return minorMatrix;
}

vector<vector<int>> FindAdditionMatrix(vector<vector<int>> &matrixToFindAddition, const int &matrixSize)
{
	vector<vector<int>> additionMatrix(matrixSize, vector<int>(matrixSize));

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if ((i + j) % 2)
			{
				additionMatrix[i][j] = (-1) * matrixToFindAddition[i][j];
			}
			else
			{
				additionMatrix[i][j] = matrixToFindAddition[i][j];
			}
		}
	}

	return additionMatrix;
}

vector<vector<int>> FindTransposedMatrix(vector<vector<int>> &matrixToTranspose, const int &matrixSize)
{
	vector<vector<int>> transposedMatrix(matrixSize, vector<int>(matrixSize));

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			transposedMatrix[i][j] = matrixToTranspose[j][i];
		}
	}

	return transposedMatrix;
}

vector<vector<double>> FindInverseMatrix(vector<vector<int>> &matrixToInvert, const int &matrixSize, const int &determinant)
{
	vector<vector<int>> minorMatrix(matrixSize, vector<int>(matrixSize));
	minorMatrix = FindMinorMatrix(matrixToInvert, matrixSize);

	vector<vector<int>> additionMatrix(matrixSize, vector<int>(matrixSize));
	additionMatrix = FindAdditionMatrix(minorMatrix, matrixSize);

	vector<vector<int>> transposedMatrix(matrixSize, vector<int>(matrixSize));
	transposedMatrix = FindTransposedMatrix(additionMatrix, matrixSize);

	vector<vector<double>> inverseMatrix(matrixSize, vector<double>(matrixSize));
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			inverseMatrix[i][j] = ((double)transposedMatrix[i][j]) / (double)determinant;
		}
	}

	return inverseMatrix;
}

bool invertMatrix(const string &inputFileName, status &statusCode, const int &matrixSize)
{
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		statusCode = INPUT_FILE_NOT_OPENED;
		return false;
	}

	vector<vector<int>> matrix(matrixSize, vector<int>(matrixSize));
	vector<vector<int>> singleOneMatrix(matrixSize, vector<int>(matrixSize));	
	defineSingleOneMatrix(singleOneMatrix, matrixSize);	
	
	while (!inputFile.eof())
	{
		char letter;
		for (int i = 0; i < matrixSize; i++)
		{
			letter = inputFile.get();
			while ((letter != '\n') && (!inputFile.eof()))
			{				
				for (int j = 0; j < matrixSize; j++)
				{
					string numberToParse = "";					
					while ((letter != ' ') && (letter != '\n') && (!inputFile.eof()))
					{						
						numberToParse = numberToParse + letter;
						letter = inputFile.get();					
					}

					char *stringPtr = &numberToParse[0];
					matrix[i][j] = strtol(stringPtr, NULL, 10);					

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

	cout << "Original matrix: " << endl;
	printSquareMatrix(matrix, matrixSize);
	cout << endl;

	int determinant = FindDeterminantForMatrixThreeOnThree(matrix);
	if (determinant == 0)
	{
		statusCode = DETERMINANT_ZERO;
		return false;
	}
	else
	{
		vector<vector<double>> inverseMatrix(matrixSize, vector<double>(matrixSize));
		inverseMatrix = FindInverseMatrix(matrix, matrixSize, determinant);

		cout << "Inverse matrix: " << endl;
		printSquareMatrixTypeDouble(inverseMatrix, matrixSize);
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
	const int matrixSize = 3;
	if (!invertMatrix(argv[1], statusCode, matrixSize))
	{
		printError(statusCode);
		return 1;
	}

	return 0;
}