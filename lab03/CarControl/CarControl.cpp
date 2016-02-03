// CarControl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include "CarControlUtils.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string userCommand;
	CCar car;
	cout << "Type command to drive or \"exit\" to exit from emulator." << endl;

	getline(cin, userCommand);
	while (userCommand != "exit")
	{
		ProcessCommand(userCommand, car);
		getline(cin, userCommand);
	}	

	return 0;
}

