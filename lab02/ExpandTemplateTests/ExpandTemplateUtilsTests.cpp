#include "stdafx.h"
#include <string>
#include "../ExpandTemplate/ExpandTemplateUtils.h"

using namespace std;

map<string, string> simpleParams = {
	{ "%USER_NAME%", "Aleksey" },
	{ "{WEEK_DAY}", "Thursday" }
};

map<string, string> letterParams = {
	{ "A", "[a]" },
	{ "AA", "[aa]" },
	{ "B", "[b]" },
	{ "BB", "[bb]" },
	{ "C", "[c]" },
	{ "CC", "[cc]" }
};

BOOST_AUTO_TEST_SUITE(Replace_function)

	BOOST_AUTO_TEST_CASE(returns_string_with_replaced_markers)
	{
		string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
		string expectedResult = "Hello, Aleksey. Today is Thursday.";

		string result = ExpandTemplate(tpl, simpleParams);
		
		BOOST_CHECK_EQUAL(result, expectedResult);
	}

	BOOST_AUTO_TEST_CASE(returns_string_with_replaced_repeating_markers)
	{
		string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}, %USER_NAME%! Still {WEEK_DAY}.";
		string expectedResult = "Hello, Aleksey. Today is Thursday, Aleksey! Still Thursday.";

		string result = ExpandTemplate(tpl, simpleParams);

		BOOST_CHECK_EQUAL(result, expectedResult);
	}

	BOOST_AUTO_TEST_CASE(does_not_replace_already_replaced_markers)
	{
		string const letterTpl = "-AABBCCCCCABC+";
		string expectedResult = "-[aa][bb][cc][cc][c][a][b][c]+";

		string result = ExpandTemplate(letterTpl, letterParams);

		BOOST_CHECK_EQUAL(result, expectedResult);
	}

BOOST_AUTO_TEST_SUITE_END()