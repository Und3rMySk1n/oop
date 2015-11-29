#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>

using namespace std;

//1. не передавать константу bitsNumber - лишний параметр
//2. atol -> atoi (чтобы е преобразовывать из long в int
//3. вместо int использовать int8t

enum status
{
	OK, ERROR
};

int GetNumberFromString(char *inputNumberString, status &statusCode)
{
	char *endOfString = NULL;
	int numberToFlip = strtol(inputNumberString, &endOfString, 10);
	if (*endOfString != NULL)
	{
		cout << "You should enter a number without letters." << endl;
		statusCode = ERROR;
		return 0;
	}
	else if ((numberToFlip < 0) || (numberToFlip > 255))
	{
		cout << "The number must be from 0 to 255." << endl;
		statusCode = ERROR;
		return 0;
	}

	return numberToFlip;
}

int FlipByte(int numberToFlip, int bitsNumber)
{	
	int flippedNumber = 0;

	for (int i = 0; i < bitsNumber; i++)
	{
		int bit = 1 << i;
		bit = bit & numberToFlip;
		
		int shift = (bitsNumber - 1) - (2 * i);
		bit = (shift > 0) ? bit << shift : bit >> shift * (-1);	

		flippedNumber = flippedNumber | bit;
	}  

	return flippedNumber;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "You should enter a number." << endl;
		return 1;
	}
	else
	{
		cout << "This program flips byte: it reverses binary presence of entered number." << endl;	
	}
	
	char *inputNumberString = argv[1];
	const int bitsNumber = 8;
	status statusCode = OK;

	int numberToFlip = GetNumberFromString(inputNumberString, statusCode);
	if (statusCode == OK)
	{
		int flippedNumber = FlipByte(numberToFlip, bitsNumber);
		cout << flippedNumber << endl;
	}
	else
	{
		return 1;
	}
	
	return 0;
}