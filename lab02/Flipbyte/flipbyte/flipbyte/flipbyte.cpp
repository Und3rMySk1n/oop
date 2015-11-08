#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string TurnToReversedBinary(int NumberToFlip, const int &blockSize)
{	
	char rest;	
	string binaryNumberInString = "";
	for (int i = 0; i < blockSize; i++)
	{		 
		rest = NumberToFlip % 2;
		NumberToFlip = NumberToFlip / 2;
		rest = rest + '0';
		binaryNumberInString += rest;
	}

	return binaryNumberInString;
}

int TurnToDecimal(string flippedBinaryNumber)
{
	int resultNumber = 0;
	int power = 0;
	int sizeOfString = flippedBinaryNumber.length();
	for (int i = sizeOfString - 1; i >= 0; i--)
	{
		if (flippedBinaryNumber[i] == '1')
		{
			resultNumber = resultNumber + pow(2, power);
		}

		++power;
	}

	return resultNumber;
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
	
	char *endOfString = NULL;
	int NumberToFlip = strtol(argv[1], &endOfString, 10);
	if (*endOfString != NULL)
	{
		cout << "You should enter a number without letters." << endl;
		return 1;
	}
	else if ((NumberToFlip < 0) || (NumberToFlip > 255))
	{
		cout << "The number must be from 0 to 255." << endl;
		return 1;
	}

	const int blocksize = 8;
	string flippedBinaryNumber = TurnToReversedBinary(NumberToFlip, blocksize);
	int flippedNumber = TurnToDecimal(flippedBinaryNumber);

	cout << "Flipped number is: " << flippedNumber << endl;
	return 0;
}