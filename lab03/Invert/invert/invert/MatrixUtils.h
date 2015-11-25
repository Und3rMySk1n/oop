#pragma once
#include <vector>

using namespace std;

void printSquareMatrix(vector<vector<int>> &matrixToPrint, const int &matrixSize);

void printSquareMatrixTypeDouble(vector<vector<double>> &matrixToPrint, const int &matrixSize);

int FindDeterminantForMatrix_2x2(vector<vector<int>> &matrixTwoOnTwo);

vector<vector<int>> FindRestOfMatrix(vector<vector<int>> &matrixToFindRest, int matrixSize, int thisString, int thisColumn);

int FindDeterminantForMatrix_3x3(vector<vector<int>> &matrixThreeOnThree);

void defineSingleOneMatrix(vector<vector<int>> &matrixToDefine, const int &matrixSize);

vector<vector<int>> FindMinorMatrix_3x3(vector<vector<int>> &matrixToFindMinor);

vector<vector<int>> FindAdditionMatrix_3x3(vector<vector<int>> &matrixToFindAddition);

vector<vector<int>> FindTransposedSquareMatrix(vector<vector<int>> &matrixToTranspose, const int &matrixSize);

vector<vector<double>> FindInverseMatrix_3x3(vector<vector<int>> &matrixToInvert, const int &determinant);
