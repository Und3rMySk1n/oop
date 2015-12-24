// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "DictionaryUtils.h"

enum statusCode
{
	OK, INPUT_FILE_NOT_OPENED, OUTPUT_FILE_NOT_WRITTEN
};

bool InitializeDictionaryFile(std::string inputFileName, statusCode &status)
{
	std::ifstream dictionaryFile(inputFileName);
	if (!dictionaryFile.is_open())
	{
		status = INPUT_FILE_NOT_OPENED;
		return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");	

	std::map<std::string, std::string> dictionary;
	statusCode status = OK;

	if (argc == 2)
	{
		std::string fileName = argv[1];
		std::ifstream dictionaryFile(fileName);

		if (!dictionaryFile.is_open())
		{
			status = INPUT_FILE_NOT_OPENED;
			return 1;
		}

		ReadDictionaryFromFile(dictionaryFile, dictionary);
	}	
	
	std::string word, translation, temp;
	AddTranslation(dictionary, "window", "окно");

	while (word != "...")
	{
		std::getline(std::cin, word);
		translation = GetTranslation(dictionary, word);
		if (translation != "")
		{
			std::cout << "Translation: " << dictionary[word] << std::endl;
		}
		else if (word != "...")
		{
			std::cout << "Неизвестное слово \"" << word 
				      << "\" Введите перевод или пустую строку для отказа." << std::endl;
			std::getline(std::cin, translation);
			if (translation != "")
			{
				AddTranslation(dictionary, word, translation);
			}
		}		
	}

	std::cout << "Good bye!" << std::endl;

	return 0;
}