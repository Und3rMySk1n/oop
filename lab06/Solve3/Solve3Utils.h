#pragma once

#include "stdafx.h"

struct EquationRoots3
{
	int numRoots;
	double roots[3];
};

double ReturnSign(double number);

EquationRoots3 Solve3(double a, double b, double c, double d);

EquationRoots3 Solve3SimplifiedEquation(double a, double b, double c);

EquationRoots3 Solve3ForThreeRealRoots(double a, double b, double c, double q, double r);

EquationRoots3 Solve3ForOneRealAndTwoComplexRoots(double a, double b, double c, double q, double r);