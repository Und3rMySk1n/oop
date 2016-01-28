#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>


using namespace std;

BodyPtrVector bodiesVector;

enum commandsType
{
	create, show
};

enum bodiesType
{
	sphere, parallelepiped, cone, cylinder
};

map<string, commandsType> availableCommands = { 
	{ "create", commandsType::create },
	{ "show", commandsType::show }
};

map<string, bodiesType> availableBodies = {
	{ "sphere", bodiesType::sphere },
	{ "parallelepiped", bodiesType::parallelepiped },
	{ "cone", bodiesType::cone },
	{ "cylinder", bodiesType::cylinder }
};

bool ProcessCommand(std::string const & command, std::istream & is)
{
	commandsType currentCommand;

	auto it = availableCommands.find(command);
	if (it != availableCommands.end())
	{
		currentCommand = it->second;
		BodyPtr newBody = nullptr;
		
		switch (currentCommand)
		{
		case show:
			cout << "Showing all bodies..." << endl;
			break;
		case create:
			AddBody(is, bodiesVector);
			break;
		default: 
			break;			
		}

		return true;
	}

	return false;	
}

void AddBody(std::istream & is, BodyPtrVector &bodiesVector)
{
	BodyPtr ptr = nullptr;
	string bodyName, argName;
	bodiesType currentBody;
	vector<double> args;

	is >> bodyName;

	auto it = availableBodies.find(bodyName);
	if (it != availableBodies.end())
	{
		currentBody = it->second;		

		switch (currentBody)
		{
		case sphere:
			cout << "Creating sphere..." << endl;
			//ptr = CreateSphere(args);
			break;
		case parallelepiped:
			cout << "Creating parallelepiped..." << endl;
			break;
		case cone:
			cout << "Creating cone..." << endl;
			break;
		case cylinder:
			cout << "Creating cylinder..." << endl;
			break;
		default:
			break;
		}		
	}
	else
	{
		cout << "There's no body with this name." << endl;
	}

	if (ptr != nullptr)
	{
		bodiesVector.push_back(ptr);
	}
}

BodyPtr CreateSphere(vector<double> &args)
{
	BodyPtr sphere = make_shared<CSphere>(args.at(0), args.at(1));
	cout << "Sphere with density <" << args.at(0) << "and radius <" << args.at(1) << "> created" << endl;
	return sphere;
}