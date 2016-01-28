// bodies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "UserInterface.h"

using namespace std;

int main(int argc, char* argv[])
{	
	string command = "";
	
	cout << "Available commands:" << endl 
	 	 << " create <body type> <args> - creates body" << endl
		 << " show - shows all bodies" << endl
		 << " exit - exits from dialogue" << endl << endl;

	cin >> command;
	while (command != "exit")
	{
		if (!ProcessCommand(command, cin))
		{
			cout << "Enter correct command" << endl;
		}
		cin >> command;
	}

	return 0;
}
