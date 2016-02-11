// task2_myArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyArray.h"

using namespace std;

int main(int argc, char* argv[])
{
	CMyArray<double> myArray;

	myArray.AddElement(1.005);
	myArray.AddElement(2.15);
	myArray.AddElement(3.56);
	myArray.AddElement(4);
	myArray.AddElement(5);

	myArray[3] = 3333.223;

	try
	{
		for (int i = 0; i < 6; i++)
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

