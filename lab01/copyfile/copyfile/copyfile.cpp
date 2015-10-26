#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>

using namespace std;

enum status
{
	OK, INPUT_FILE_NOT_OPENED, OUTPUT_FILE_NOT_WRITTEN, READ_ERROR
};

bool copyInputFileToOutputFile(string inputFileName, string outputFileName, status &statusCode)
{
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		statusCode = INPUT_FILE_NOT_OPENED;
		return false;
	}

	ofstream outputFile(outputFileName);
	if (!outputFile.is_open())
	{
		statusCode = OUTPUT_FILE_NOT_WRITTEN;
		return false;
	}

	string lineToWrite;
	while (!inputFile.eof())
	{
		if (!getline(inputFile, lineToWrite))
		{
			statusCode = READ_ERROR;
			return false;
		}
		else
		{
			outputFile << lineToWrite << endl;
		}
	}	

	return true;
}

void printError(status &statusCode)
{
	switch (statusCode)
	{
	    case INPUT_FILE_NOT_OPENED:
		{
			cout << "File open failed." << endl;
			break;
		}
	    case OUTPUT_FILE_NOT_WRITTEN:
		{
			cout << "File writing failed." << endl;
			break;
		}
	    case READ_ERROR:
		{
			cout << "File reading error." << endl;
		}
	}
}

int main(int argc, char* argv[])
{	
	if (argc != 3)
	{
		cout << "You should enter 2 file names." << endl;
		return 1;
	}
	else
	{
		cout << "This program copies first file in command line to second file." << endl;
	}

	status statusCode = OK;
	if (!copyInputFileToOutputFile(argv[1], argv[2], statusCode))
	{
		printError(statusCode);
		return 1;
	}
	
	cout << "File <" << argv[1] << "> copied to <" << argv[2] << "> succesfully." << endl;
	return 0;	
}