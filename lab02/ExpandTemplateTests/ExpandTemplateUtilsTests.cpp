#include "stdafx.h"
#include <string>
#include "../ExpandTemplate/ExpandTemplateUtils.h"

using namespace std;

map<string, string> simpleParams = {
	{ "%USER_NAME%", "Aleksey" },
	{ "{WEEK_DAY}", "Thursday" }
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

BOOST_AUTO_TEST_SUITE_END()