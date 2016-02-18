// Solve3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solve3Utils.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		EquationRoots3 result = Solve3(4.0, 5.0, 7.0, 2.0);
		cout << result.numRoots << endl;
		for (int i = 0; i < result.numRoots; i++)
		{
			cout << "root[" << i << "] = " << result.roots[i] << endl;
		}
	}
	catch (const std::invalid_argument &e)
	{
		cout << e.what() << endl;
	}
	

	return 0;
}

