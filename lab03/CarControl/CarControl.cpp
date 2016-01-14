// CarControl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Car.h"
#include "CarControlUtils.h"
#include <map>

using namespace std;

map<string, CCar::Gear> gearNames = { { "reverse", CCar::Gear::reverse },
									  { "neutral", CCar::Gear::neutral },
									  { "first", CCar::Gear::first },
									  { "second", CCar::Gear::second },
									  { "third", CCar::Gear::third },
									  { "fourth", CCar::Gear::fourth },
									  { "fifth", CCar::Gear::fifth } };

int main(int argc, char* argv[])
{
	string userCommand;
	CCar car;
	cout << "Type command to drive or \"exit\" to exit from emulator." << endl;

	while (userCommand != "exit")
	{
		getline(cin, userCommand);

		if (userCommand == "Info")
		{
			ShowInfo(car);
		}
		else if (userCommand == "EngineOn")
		{
			if (car.TurnOnEngine())
			{
				cout << "Engine is on now" << endl;
			}
			else
			{
				cout << "Couldn't set engine on" << endl;
			}
		}
		else if (userCommand == "EngineOff")
		{
			if (car.TurnOffEngine())
			{
				cout << "Engine is off now." << endl;
			}
			else
			{
				cout << "Couldn't set engine off." << endl;
			}
		}
		else if (userCommand.substr(0, 7) == "SetGear")
		{
			userCommand.erase(0, 8);
			CCar::Gear gear = gearNames.at(userCommand);

			if (car.SetGear(gear))
			{
				cout << "Gear is shifted to " << userCommand << endl;
			}
			else
			{
				cout << "You can't shift gear to " << userCommand << endl;
			}
		}
		else if (userCommand.substr(0, 8) == "SetSpeed")
		{
			userCommand.erase(0, 9);
			int newSpeed = stoi(userCommand, nullptr);

			if (car.SetSpeed(newSpeed))
			{
				cout << "Speed is set to " << newSpeed << endl;
			}
			else
			{
				cout << "You can't set speed " << newSpeed << " now." << endl;
			}
		}
		else if (userCommand != "exit")
		{
			cout << "Unknown command." << endl;
		}
	}	

	return 0;
}

