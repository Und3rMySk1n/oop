#include "stdafx.h"
#include "DictionaryUtils.h"

std::string GetTranslation(std::map<std::string, std::string> &dictionary, const std::string &word)
{
	return dictionary[word];
}

void AddTranslation(std::map<std::string, std::string> &dictionary, const std::string &word, const std::string &translation)
{
	dictionary.insert(std::pair<std::string, std::string>(word, translation));
}

bool ReadDictionaryFromFile(std::ifstream &dictionaryFile, std::map<std::string, std::string> &dictionary)
{
	std::string formattedString, word, translation;

	while (!dictionaryFile.eof())
	{
		std::getline(dictionaryFile, formattedString);
		
		std::size_t divider = formattedString.find(':');
		if (divider != std::string::npos)
		{
			word = formattedString.substr(0, divider);
			translation = formattedString.substr(divider + 1, std::string::npos);
			
			AddTranslation(dictionary, word, translation);
		}
	}

	return true;
}