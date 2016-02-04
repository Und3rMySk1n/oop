// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Triangle.h"
#include "UserInterface.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Enter 3 sides of triangle." << endl;

	string commandLine;
	getline(cin, commandLine);

	while (!cin.eof())
	{			
		array<double, 3> args;

		try
		{
			args = GetArguments(commandLine);
			CTriangle triangle = CTriangle(args[0], args[1], args[2]);

			cout << "S = " << triangle.GetArea() << ", P = " << triangle.GetPerimeter() << endl;
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
		}		

		getline(cin, commandLine);
	}

	return 0;
}

