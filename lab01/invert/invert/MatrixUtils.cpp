#include "MatrixUtils.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void PrintSquareMatrix_3x3(const matrix33 &matrixToPrint)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{			
			cout << setprecision(3) << fixed << matrixToPrint[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

double FindDeterminantForRestMatrix_3x3(const matrix33 &matrixToFindRest, int thisString, int thisColumn)
{
	matrix22 restMatrix;
	int m = 0;
	int n = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i != thisString) && (j != thisColumn))
			{

				restMatrix[m][n] = matrixToFindRest[i][j];
				n++;

				if (n == 2)
				{
					n = 0;
					m++;
				}
			}
		}
	}

	double determinant = (restMatrix[0][0] * restMatrix[1][1]) -
		(restMatrix[0][1] * restMatrix[1][0]);

	return determinant;
}

double FindDeterminantForMatrix_3x3(const matrix33 &matrixThreeOnThree)
{
	double determinant = 0;
	int thisString = 0; //Ќаходим детерминант по первой строке
	int summarySign = 1;

	for (int thisColumn = 0; thisColumn < 3; thisColumn++)
	{
		double smallDeterminant = FindDeterminantForRestMatrix_3x3(matrixThreeOnThree, thisString, thisColumn);

		determinant += matrixThreeOnThree[thisString][thisColumn] * smallDeterminant * summarySign;
		summarySign = summarySign * (-1);
	}

	return determinant;
}

matrix33 FindMinorMatrix_3x3(const matrix33 &matrixToFindMinor)
{
	matrix33 minorMatrix;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double smallDeterminant = FindDeterminantForRestMatrix_3x3(matrixToFindMinor, i, j);
			minorMatrix[i][j] = smallDeterminant;
		}
	}

	return minorMatrix;
}

matrix33 FindAdditionMatrix_3x3(const matrix33 &matrixToFindAddition)
{
	matrix33 additionMatrix;

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

matrix33 FindTransposedMatrix_3x3(const matrix33 &matrixToTranspose)
{
	matrix33 transposedMatrix;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			transposedMatrix[i][j] = matrixToTranspose[j][i];
		}
	}

	return transposedMatrix;
}

matrix33 FindInverseMatrix_3x3(const matrix33 &matrixToInvert, const double &determinant)
{
	matrix33 minorMatrix = FindMinorMatrix_3x3(matrixToInvert);
	matrix33 additionMatrix = FindAdditionMatrix_3x3(minorMatrix);
	matrix33 transposedMatrix = FindTransposedMatrix_3x3(additionMatrix);

	matrix33 inverseMatrix;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inverseMatrix[i][j] = (transposedMatrix[i][j]) / determinant;
		}
	}

	return inverseMatrix;
}
