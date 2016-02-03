// HTMLEncode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HTMLUtils.h"

using namespace std;

int main(int argc, char* argv[])
{
	string inputString;	

	while (!cin.eof())
	{
		getline(cin, inputString);

		string outputString;
		outputString.reserve(inputString.size());
		outputString = HtmlEncode(inputString);

		cout << outputString << endl;
	}	

	return 0;
}

