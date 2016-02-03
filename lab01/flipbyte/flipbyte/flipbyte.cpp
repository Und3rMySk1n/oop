#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#include <cstdint>

using namespace std;

//1. не передавать константу bitsNumber - лишний параметр
//2. atol -> atoi (чтобы е преобразовывать из long в int
//3. вместо int использовать int8t

int8_t GetNumberFromString(char *inputNumberString)
{
	char numberToFlip = atoi(inputNumberString);

	if ((numberToFlip < 0) || (numberToFlip > 255))
	{
		cout << "The number must be from 0 to 255." << endl;
		return 0;
	}

	return numberToFlip;
}

int8_t FlipByte(int8_t numberToFlip)
{	
	int8_t flippedNumber = 0;

	for (char i = 0; i < 8; i++)
	{
		char bit = 1 << i;
		bit = bit & numberToFlip;
		
		char shift = (8 - 1) - (2 * i);
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
	int8_t numberToFlip = GetNumberFromString(inputNumberString);
	int8_t flippedNumber = FlipByte(numberToFlip);
	cout << flippedNumber << endl;	
	
	return 0;
}