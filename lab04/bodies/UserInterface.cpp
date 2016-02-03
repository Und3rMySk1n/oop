#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>
#include <array>


using namespace std;

bool ProcessCommand(string &commandLine, BodyPtrVector &bodiesVector)
{
	if (commandLine == "show")
	{
		ShowBodies(bodiesVector);
		return true;
	}
	if (commandLine == "showMax")
	{
		BodyPtr maxBody = GetHeaviestBody(bodiesVector);

		if (maxBody == nullptr)
		{
			cout << "No bodies entered." << endl;
		}
		else
		{
			cout << "Body with max mass: " << endl << maxBody->ToString() << endl;
		}
		
		return true;
	}
	else if (commandLine == "showLightest")
	{
		BodyPtr lightestBody = GetLightestInWater(bodiesVector);
		if (lightestBody == nullptr)
		{
			cout << "No bodies entered." << endl;
		}
		else
		{
			cout << "Lightest body in water: " << endl << lightestBody->ToString() << endl
				<< "It's mass in water is: " << GetMassInWater(lightestBody) << endl;
		}		
		return true;
	}
	else if (commandLine.substr(0, 7) == "create ")
	{
		AddBody(commandLine, bodiesVector);
		return true;
	}

	return false;	
}

void ShowBodies(BodyPtrVector &bodiesVector)
{
	if (bodiesVector.empty())
	{
		cout << "No bodies entered." << endl;
	}
	else
	{
		for (auto it : bodiesVector)
		{
			cout << it->ToString() << endl;
		}
	}	
}

void AddBody(string &commandLine, BodyPtrVector &bodiesVector)
{
	commandLine.erase(0, 7);
	string bodyType = CutParamFromString(commandLine);
	
	if (bodyType == "sphere")
	{
		AddSphere(commandLine, bodiesVector);
	}
	else if (bodyType == "parallelepiped")
	{
		AddParallelepiped(commandLine, bodiesVector);
	}
	else if (bodyType == "cone")
	{
		AddCone(commandLine, bodiesVector);
	}
	else if (bodyType == "cylinder")
	{
		AddCylinder(commandLine, bodiesVector);
	}
	else
	{
		cout << "Type correct command with arguments." << endl;
	}

}

string CutParamFromString(string &commandLine)
{
	size_t found = commandLine.find(" ");
	string command = "";

	if (found != string::npos)
	{
		command = commandLine.substr(0, found);
		commandLine.erase(0, found + 1);
	}

	return command;
}

array<double, 4> GetArgumentsFromString(string &commandLine, const int numOfArgs)
{
	array<double, 4> args;
	size_t nextNumberPtr;

	try
	{
		for (char i = 0; i < numOfArgs; i++)
		{
			args[i] = stod(commandLine, &nextNumberPtr);
			commandLine.erase(0, nextNumberPtr);			
		}
	}
	catch (invalid_argument e)
	{
		throw invalid_argument("Wrong number of parameters.");
	}	

	return args;
}

bool AddSphere(string &commandLine, BodyPtrVector &bodiesVector)
{
	array<double, 4> args;

	try
	{
		args = GetArgumentsFromString(commandLine, 2);

		BodyPtr sphere = make_shared<CSphere>(args[0], args[1]);
		bodiesVector.push_back(sphere);
		cout << "Sphere width density " << args[0] << " and radius " << args[1] << " added." << endl;

		return true;		
	}
	catch (invalid_argument e)
	{
		cout << "Enter valid parameters: " << endl
			<< "  create sphere <density> <radius>" << endl;
	}			

	return false;
}

bool AddCone(string &commandLine, BodyPtrVector &bodiesVector)
{
	array<double, 4> args;

	try
	{
		args = GetArgumentsFromString(commandLine, 3);

		BodyPtr cone = make_shared<CCone>(args[0], args[1], args[2]);
		bodiesVector.push_back(cone);
		cout << "Cone width density " << args[0] << ", radius " << args[1]
			<< " and height " << args[2] << " added." << endl;

		return true;
	}
	catch (invalid_argument e)
	{
		cout << "Enter valid parameters: " << endl
			<< "  create cone <density> <radius> <height>" << endl;
	}

	return false;
}

bool AddParallelepiped(string &commandLine, BodyPtrVector &bodiesVector)
{
	array<double, 4> args;

	try
	{
		args = GetArgumentsFromString(commandLine, 4);

		BodyPtr parallelepiped = make_shared<CParallelepiped>(args[0], args[1], args[2], args[3]);
		bodiesVector.push_back(parallelepiped);
		cout << "Parallelepiped width density " << args[0] << ", width " << args[1]
			<< ", height " << args[2] << " and depth " << args[3] << " added." << endl;

		return true;
	}
	catch (invalid_argument e)
	{
		cout << "Enter valid parameters: " << endl
			<< "  create parallelepiped <density> <width> <height> <depth>" << endl;
	}

	return false;
}

bool AddCylinder(string &commandLine, BodyPtrVector &bodiesVector)
{
	array<double, 4> args;

	try
	{
		args = GetArgumentsFromString(commandLine, 3);

		BodyPtr cylinder = make_shared<CCylinder>(args[0], args[1], args[2]);
		bodiesVector.push_back(cylinder);
		cout << "Cylinder width density " << args[0] << ", radius " << args[1]
			<< " and height " << args[2] << " added." << endl;

		return true;
	}
	catch (invalid_argument e)
	{
		cout << "Enter valid parameters: " << endl
			<< "  create cylinder <density> <radius> <height>" << endl;
	}

	return false;
}

BodyPtr GetHeaviestBody(BodyPtrVector &bodiesVector)
{
	BodyPtr maxBody = nullptr;

	if (!bodiesVector.empty())
	{
		maxBody = bodiesVector.at(0);

		for (auto it : bodiesVector)
		{
			if (it->GetMass() > maxBody->GetMass())
			{
				maxBody = it;
			}
		}		
	}

	return maxBody;
}

BodyPtr GetLightestInWater(BodyPtrVector &bodiesVector)
{	
	BodyPtr lightestBody = nullptr;

	if (!bodiesVector.empty())
	{
		lightestBody = bodiesVector.at(0);

		for (auto it : bodiesVector)
		{
			if (GetMassInWater(it) < GetMassInWater(lightestBody))
			{
				lightestBody = it;
			}
		}
	}

	return lightestBody;
}

double GetMassInWater(BodyPtr const &body)
{
	double massInWater = body->GetMass() * 9.8 - body->GetVolume() * 9.8 * 1000;
	return massInWater;
}