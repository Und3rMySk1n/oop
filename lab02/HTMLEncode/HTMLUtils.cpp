#include "stdafx.h"
#include "HTMLUtils.h"

std::string HtmlEncode(std::string const &text)
{
	std::string newString;
	for (unsigned int i = 0; i < text.length(); i++)
	{
		switch (text[i])
		{
		case '\"':
			newString += "&quot;";
			break;
		case '\'':
			newString += "&apos;";
			break;
		case '<':
			newString += "&lt;";
			break;
		case '>':
			newString += "&gt;";
			break;
		case '&':
			newString += "&amp;";
			break;		
		default:
			newString += text[i];
			break;
		}		
	}

	return newString;
}