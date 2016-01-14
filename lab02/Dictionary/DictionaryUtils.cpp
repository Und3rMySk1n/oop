#include "stdafx.h"
#include "DictionaryUtils.h"

using namespace std;

string GetTranslation(map<string, string> &dictionary, const string &word)
{
	auto it = dictionary.find(word);
	return (it != dictionary.end()) ? it->second : "";
}

void AddTranslation(map<string, std::string> &dictionary, const string &word, const string &translation)
{
	dictionary.emplace(word, translation);
}

bool ReadDictionaryFromFile(ifstream &dictionaryFile, map<string, string> &dictionary)
{
	string formattedString, word, translation;

	while (!dictionaryFile.eof())
	{
		getline(dictionaryFile, formattedString);
		
		size_t divider = formattedString.find(':');
		if (divider != string::npos)
		{
			word = formattedString.substr(0, divider);
			translation = formattedString.substr(divider + 1, string::npos);
			
			AddTranslation(dictionary, word, translation);
		}
	}

	return true;
}

bool WriteDictionaryToFile(ofstream &dictionaryFile, map<string, string> const &dictionary)
{
	for (auto it = dictionary.begin(); it != dictionary.end(); it++)
	{
		dictionaryFile << it->first << ":" << it->second << endl;
	}

	return true;
}