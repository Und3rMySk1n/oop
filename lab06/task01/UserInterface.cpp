#include "stdafx.h"
#include "UserInterface.h"

using namespace std;

array<double, 3> GetArguments(string &commandLine)
{
	array<double, 3> args = { 0 };
	size_t nextNumberPointer;

	try
	{
		for (char i = 0; i < 3; i++)
		{
			args[i] = stod(commandLine, &nextNumberPointer);
			commandLine.erase(0, nextNumberPointer);
		}
	}
	catch (invalid_argument)
	{
		throw invalid_argument("All three parameters must be numbers.");
	}

	return args;
}