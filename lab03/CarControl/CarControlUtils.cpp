#include "stdafx.h"
#include "CarControlUtils.h"
#include <iostream>
#include <string>

using namespace std;

map<string, CCar::Gear> gearNames = { { "reverse", CCar::Gear::reverse },
									  { "neutral", CCar::Gear::neutral },
									  { "first", CCar::Gear::first },
									  { "second", CCar::Gear::second },
									  { "third", CCar::Gear::third },
								  	  { "fourth", CCar::Gear::fourth },
									  { "fifth", CCar::Gear::fifth } };

void ShowInfo(CCar const &car)
{
	bool isEngineOn = car.IsEngineOn();
	switch (isEngineOn)
	{
	case true:
		cout << "Engine is on" << endl;
		break;
	default:
		cout << "Engine is off" << endl;
		break;
	}	

	CCar::Direction direction = car.GetDirection();
	cout << "Direction is: ";
	switch (direction)
	{
	case CCar::Direction::backward:
		cout << "backward" << endl;
		break;
	case CCar::Direction::stop:
		cout << "stop" << endl;
		break;
	case CCar::Direction::forward:
		cout << "forward" << endl;
		break;
	}

	CCar::Gear gear = car.GetGear();
	cout << "Gear is: ";
	switch (gear)
	{
	case CCar::Gear::reverse:
		cout << "reverse" << endl;
		break;
	case CCar::Gear::neutral:
		cout << "neutral" << endl;
		break;
	case CCar::Gear::first:
		cout << "first" << endl;
		break;
	case CCar::Gear::second:
		cout << "second" << endl;
		break;
	case CCar::Gear::third:
		cout << "third" << endl;
		break;
	case CCar::Gear::fourth:
		cout << "fourth" << endl;
		break;
	case CCar::Gear::fifth:
		cout << "fifth" << endl;
		break;
	}

	cout << "Speed is: " << car.GetSpeed() << endl;
}

void ProcessCommand(string &userCommand, CCar &car)
{
	if (userCommand == "Info")
	{
		ShowInfo(car);
	}
	else if (userCommand == "EngineOn")
	{
		ProcessEngineOnCommand(car);		
	}
	else if (userCommand == "EngineOff")
	{
		ProcessEngineOffCommand(car);		
	}
	else if (userCommand.substr(0, 8) == "SetGear ")
	{
		ProcessSetGearCommand(userCommand, car);
	}
	else if (userCommand.substr(0, 9) == "SetSpeed ")
	{
		ProcessSetSpeedCommand(userCommand, car);
	}
	else
	{
		cout << "Unknown command." << endl;
	}
}

void ProcessSetGearCommand(string &userCommand, CCar &car)
{
	userCommand.erase(0, 8);
	try
	{
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
	catch (out_of_range)
	{
		cout << "Enter valid gear name." << endl;
	}
}

void ProcessSetSpeedCommand(string &userCommand, CCar &car)
{
	userCommand.erase(0, 9);

	try
	{
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
	catch (invalid_argument)
	{
		cout << "Enter valid speed." << endl;
	}
}

void ProcessEngineOffCommand(CCar &car)
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

void ProcessEngineOnCommand(CCar &car)
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