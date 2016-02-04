#include "stdafx.h"
#include "ExpandTemplateUtils.h"
#include <regex>

using namespace std;

vector<char> specialSymbols = { '{', '(', ')', '{', '}', '.', '[', '\\' , '*', '^', '$', '}' };

string ExpandTemplate(string const &tpl, map<string, string>const &params)
{
	string resultString = tpl;

	for (auto it = params.begin(); it != params.end(); it++)
	{
		try
		{
			string regularExp = EscapeStringForRegular(it->first);
			regex e(regularExp);
			resultString = regex_replace(resultString, e, it->second);
		}
		catch (regex_error &e)
		{
			cout << e.what() << endl;
		}		
	}

	return resultString;
}

string EscapeStringForRegular(string const &originalString)
{
	string result = "";

	for (unsigned int i = 0; i < originalString.size(); i++)
	{
		auto it = find(specialSymbols.begin(), specialSymbols.end(), originalString[i]);
		if (it == specialSymbols.end())
		{
			result += originalString[i];
		}
		else
		{
			result += '\\';
			result += originalString[i];
		}
		
	}

	return result;
}