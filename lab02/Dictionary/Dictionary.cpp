// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "DictionaryUtils.h"
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	map<string, string> dictionary;
	bool dictionaryChanged = false;

	if (argc == 2)
	{
		string fileName = argv[1];
		ifstream dictionaryFile(fileName);

		if (!dictionaryFile.is_open())
		{
			cout << "Не удалось открыть файл словаря." << endl;
			return 1;
		}

		ReadDictionaryFromFile(dictionaryFile, dictionary);
		dictionaryFile.close();
	}	
	
	string word, translation, temp;

	while (word != "...")
	{
		getline(cin, word);
		translation = GetTranslation(dictionary, word);
		if (translation != "")
		{
			cout << "Translation: " << translation << endl;
		}
		else if (word != "...")
		{
			cout << "Неизвестное слово \"" << word 
				      << "\" Введите перевод или пустую строку для отказа." << endl;
			getline(cin, translation);
			if (translation != "")
			{
				AddTranslation(dictionary, word, translation);
				cout << "Слово \"" << word << "\" сохранено в словаре как \"" 
					 << translation  << "\"." << endl;

				if (dictionaryChanged == false)
				{
					dictionaryChanged = true;
				}
			}
			else
			{
				cout << "Слово \"" << word << "\" проигнорировано" << endl;
			}
		}		
	}

	if (dictionaryChanged)
	{
		cout << "В словарь были внесены изменения." << endl 
			 << "Введите 'Y' или 'y' для сохранения перед выходом." << endl;

		string answer;
		getline(cin, answer);

		if ((answer == "Y") || (answer == "y"))
		{
			string outputFileName;
			if (argc == 2)
			{
				outputFileName = argv[1];
			}
			else
			{
				cout << "Введите имя файла для нового словаря: " << endl;
				getline(cin, outputFileName);
			}

			ofstream newDictionaryFile(outputFileName);
			if (!newDictionaryFile.is_open())
			{
				cout << "Не удалось записать файл словаря." << endl;
				return 1;
			}

			WriteDictionaryToFile(newDictionaryFile, dictionary);
		}
	}
	cout << "Good bye!" << endl;

	return 0;
}