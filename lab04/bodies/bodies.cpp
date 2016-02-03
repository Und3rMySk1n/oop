// bodies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "UserInterface.h"

using namespace std;

int main(int argc, char* argv[])
{	
	string commandLine;
	BodyPtrVector bodiesVector;
	
	cout << "Available commands:" << endl 
	 	 << " create <body type> <args> - creates body" << endl
		 << " show - shows all bodies" << endl
		 << " showMax - shows heaviest body" << endl
		 << " showLightest - shows lightest body in water" << endl
		 << " exit - exits from dialogue" << endl << endl;

	getline(cin, commandLine);
	while (commandLine != "exit")
	{
		if (!ProcessCommand(commandLine, bodiesVector))
		{
			cout << "Enter correct command" << endl;
		}

		getline(cin, commandLine);
	}

	return 0;
}