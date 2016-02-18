// Vehicles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CVehicle
{
public:
	virtual void Move(unsigned int distance) const
	{
		cout << "Moving " << distance << " km" << endl;
	}

	virtual ~CVehicle()
	{
	};
};

class CFlyingVehicle 
	: public CVehicle
{
public:
	void Fly(unsigned int distance) const
	{
		cout << "Flying " << distance << " km" << endl;
	}

	virtual void Move(unsigned int distance) const
	{
		Fly(distance);
	}
};

class CSailingVehicle 
	: public CVehicle
{
public:
	void Sail(unsigned int distance) const
	{
		cout << "Sailing " << distance << " km" << endl;
	}

	virtual void Move(unsigned int distance) const
	{
		Sail(distance);
	}
};

class CRidingVehicle 
	: public CVehicle
{
public:
	void Ride(unsigned int distance) const
	{
		cout << "Riding " << distance << " km" << endl;
	}

	virtual void Move(unsigned int distance) const
	{
		Ride(distance);
	}
};

class CHelicopter 
	: public CFlyingVehicle
{};

class CAirplane 
	: public CFlyingVehicle
{};

class CBus 
	: public CRidingVehicle
{};

class CCar 
	: public CRidingVehicle
{};

class CBoat 
	: public CSailingVehicle
{};

int main(int argc, char* argv[])
{
	CHelicopter helicopter;
	cout << "Helicopter: ";
	helicopter.Move(30);

	CAirplane airplane;
	cout << "Airplane: ";
	airplane.Move(800);

	CCar car;
	cout << "Car: ";
	car.Move(100);	

	CBus bus;
	cout << "Bus: ";
	bus.Move(500);

	CBoat boat;
	cout << "Boat: ";
	boat.Move(25);
	cout << "Boat using <Sail> method: ";
	boat.Sail(75);

	return 0;
}

