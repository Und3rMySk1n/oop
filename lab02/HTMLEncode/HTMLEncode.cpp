// HTMLEncode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HTMLUtils.h"

int main(int argc, char* argv[])
{
	std::string inputString;
	std::getline(std::cin, inputString);

	std::string outputString = HtmlEncode(inputString);
	std::cout << outputString;

	return 0;
}

