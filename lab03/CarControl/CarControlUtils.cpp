#include "stdafx.h"
#include "CarControlUtils.h"
#include <iostream>

using namespace std;

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