// ExpandTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ExpandTemplateUtils.h"

using namespace std;

int main(int argc, char* argv[])
{
	string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";

	map<string, string> params = { 
		{ "%USER_NAME%", "Aleksey" },
		{ "{WEEK_DAY}", "Thursday" } 
	};

	string result = ExpandTemplate(tpl, params);
	cout << result << endl;

	return 0;
}

