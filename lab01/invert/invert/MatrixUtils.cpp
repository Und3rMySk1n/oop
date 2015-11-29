#include "MatrixUtils.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

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
			cout << setprecision(3) << fixed << matrixToPrint[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

int FindDeterminantForMatrix_2x2(vector<vector<int>> &matrixTwoOnTwo)
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

int FindDeterminantForMatrix_3x3(vector<vector<int>> &matrixThreeOnThree)
{
	int determinant = 0;
	int thisString = 0; //Ќаходим детерминант по первой строке
	int summarySign = 1;

	for (int thisColumn = 0; thisColumn < 3; thisColumn++)
	{
		vector<vector<int>> matrixTwoOnTwo(2, vector<int>(2));
		matrixTwoOnTwo = FindRestOfMatrix(matrixThreeOnThree, 3, thisString, thisColumn);

		determinant += matrixThreeOnThree[thisString][thisColumn] * FindDeterminantForMatrix_2x2(matrixTwoOnTwo) * summarySign;
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

vector<vector<int>> FindMinorMatrix_3x3(vector<vector<int>> &matrixToFindMinor)
{
	vector<vector<int>> smallMatrix(2, vector<int>(2));
	vector<vector<int>> minorMatrix(3, vector<int>(3));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			smallMatrix = FindRestOfMatrix(matrixToFindMinor, 3, i, j);
			minorMatrix[i][j] = FindDeterminantForMatrix_2x2(smallMatrix);
		}
	}

	return minorMatrix;
}

vector<vector<int>> FindAdditionMatrix_3x3(vector<vector<int>> &matrixToFindAddition)
{
	vector<vector<int>> additionMatrix(3, vector<int>(3));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
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

vector<vector<int>> FindTransposedSquareMatrix(vector<vector<int>> &matrixToTranspose, const int &matrixSize)
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

vector<vector<double>> FindInverseMatrix_3x3(vector<vector<int>> &matrixToInvert, const int &determinant)
{
	vector<vector<int>> minorMatrix(3, vector<int>(3));
	minorMatrix = FindMinorMatrix_3x3(matrixToInvert);

	vector<vector<int>> additionMatrix(3, vector<int>(3));
	additionMatrix = FindAdditionMatrix_3x3(minorMatrix);

	vector<vector<int>> transposedMatrix(3, vector<int>(3));
	transposedMatrix = FindTransposedSquareMatrix(additionMatrix, 3);

	vector<vector<double>> inverseMatrix(3, vector<double>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inverseMatrix[i][j] = ((double)transposedMatrix[i][j]) / (double)determinant;
		}
	}

	return inverseMatrix;
}
