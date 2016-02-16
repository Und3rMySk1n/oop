// task2_myArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyArray.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	CMyArray<string> myArray;

	myArray.AddElement("One");
	myArray.AddElement("Two");
	myArray.AddElement("Three");
	myArray.AddElement("Seven");
	myArray.AddElement("Five");

	myArray[3] = "Four";

	try
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Element [" << i << "] = " << myArray[i] << endl;
		}
		cout << "Size: " << myArray.GetSize() << endl;

		cout << "--- After clear ---" << endl;
		myArray.Clear();
		cout << "Element [0] = " << myArray[0] << endl;
		cout << "Size: " << myArray.GetSize() << endl;
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}	

	return 0;
}

