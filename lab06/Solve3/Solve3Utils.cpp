#include "stdafx.h"
#include "Solve3Utils.h"
#include <iostream>

using namespace std;

double ReturnSign(double number)
{
	if (number < 0.0)
	{
		return -1.0;
	}
	else if (number > 0.0)
	{
		return 1.0;
	}

	return 0.0;
}

EquationRoots3 Solve3(double a, double b, double c, double d)
{
	if (a == 0)
	{
		throw invalid_argument("First coefficient can not be zero.");
	}

	EquationRoots3 result = Solve3SimplifiedEquation(b / a, c / a, d / a);
	return result;
}

EquationRoots3 Solve3SimplifiedEquation(double a, double b, double c)
{
	double q = (a * a - 3.0 * b) / 9.0;
	double r = (2.0 * a * a * a - 9.0 * a * b + 27.0 * c) / 54.0;

	EquationRoots3 result;

	if (r * r < q * q * q)
	{
		result = Solve3ForThreeRealRoots(a, b, c, q, r);
	}
	else
	{
		result = Solve3ForOneRealAndTwoComplexRoots(a, b, c, q, r);
	}

	return result;
}

EquationRoots3 Solve3ForThreeRealRoots(double a, double b, double c, double q, double r)
{
	EquationRoots3 result;
	double t = (acos(r / sqrt(q*q*q))) / 3.0;
	
	result.numRoots = 3;
	result.roots[0] = -2.0 * sqrt(q) * cos(t) - a / 3.0;
	result.roots[1] = -2.0 * sqrt(q) * cos(t + 2.0 * M_PI / 3.0) - a / 3.0;
	result.roots[2] = -2.0 * sqrt(q) * cos(t - 2.0 * M_PI / 3.0) - a / 3.0;

	return result;
}

EquationRoots3 Solve3ForOneRealAndTwoComplexRoots(double a, double b, double c, double q, double r)
{
	EquationRoots3 result;

	double A, B;

	double sign = ReturnSign(r);
	A = -1 * sign * pow(r + sqrt(r*r*r - q*q*q), 1. / 3.);
	B = (A != 0.0) ? q / A : 0.0;

	result.roots[0] = A + B - a / 3.0;
	result.roots[1] = (-0.5) * (A + B) - a;
	result.roots[2] = (sqrt(3.0) * 0.5) * abs(A - B);

	result.numRoots = (result.roots[2] == 0.0) ? 2 : 1;

	return result;
}