#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>

typedef std::array<double, 3> matrix3;
typedef std::array<matrix3, 3> matrix33;

typedef std::array<double, 2> matrix2;
typedef std::array<matrix2, 2> matrix22;


void PrintSquareMatrix_3x3(const matrix33 &matrixToPrint);

int FindDeterminantForMatrix_2x2(const matrix22 &matrixTwoOnTwo);

double FindDeterminantForMatrix_3x3(const matrix33 &matrixThreeOnThree);

double FindDeterminantForRestMatrix_3x3(const matrix33 &matrixToFindRest, int thisString, int thisColumn);

matrix33 FindMinorMatrix_3x3(const matrix33 &matrixToFindMinor);

matrix33 FindAdditionMatrix_3x3(const matrix33 &matrixToFindAddition);

matrix33 FindTransposedMatrix_3x3(const matrix33 &matrixToTranspose);

matrix33 FindInverseMatrix_3x3(const matrix33 &matrixToInvert, const double &determinant);
