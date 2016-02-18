// task2_myArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyArray.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	CMyArray<string> myArray;	

	try
	{
		myArray.AddElement("One");
		myArray.AddElement("Two");
		myArray.AddElement("Three");
		myArray.AddElement("Seven");
		myArray.AddElement("Five");

		myArray[3] = "Four";

		for (int i = 0; i < 5; i++)
		{
			cout << "Element [" << i << "] = " << myArray[i] << endl;
		}
		cout << "Size: " << myArray.GetSize() << endl;
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}	

	try
	{
		CMyArray<string> newArray;
		newArray = myArray;
		cout << endl << "newArray[2]: " << newArray[2] << endl;
		cout << endl << "newArraySize: " << newArray.GetSize() << endl;

		myArray.Resize(3);
		cout << endl << "myArray[19]: " << myArray[3] << endl;
	}
	catch (const std::bad_alloc)
	{
		cout << "Failed to allocate." << endl;
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}
	
	

	return 0;
}

