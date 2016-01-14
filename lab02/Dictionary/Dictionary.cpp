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
			cout << "�� ������� ������� ���� �������." << endl;
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
			cout << "����������� ����� \"" << word 
				      << "\" ������� ������� ��� ������ ������ ��� ������." << endl;
			getline(cin, translation);
			if (translation != "")
			{
				AddTranslation(dictionary, word, translation);
				cout << "����� \"" << word << "\" ��������� � ������� ��� \"" 
					 << translation  << "\"." << endl;

				if (dictionaryChanged == false)
				{
					dictionaryChanged = true;
				}
			}
			else
			{
				cout << "����� \"" << word << "\" ���������������" << endl;
			}
		}		
	}

	if (dictionaryChanged)
	{
		cout << "� ������� ���� ������� ���������." << endl 
			 << "������� 'Y' ��� 'y' ��� ���������� ����� �������." << endl;

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
				cout << "������� ��� ����� ��� ������ �������: " << endl;
				getline(cin, outputFileName);
			}

			ofstream newDictionaryFile(outputFileName);
			if (!newDictionaryFile.is_open())
			{
				cout << "�� ������� �������� ���� �������." << endl;
				return 1;
			}

			WriteDictionaryToFile(newDictionaryFile, dictionary);
		}
	}
	cout << "Good bye!" << endl;

	return 0;
}