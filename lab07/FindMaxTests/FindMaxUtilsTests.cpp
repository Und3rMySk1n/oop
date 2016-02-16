#include "stdafx.h"
#include "../FindMax/FindMaxUtils.cpp"

using namespace std;

const vector<int> emptyVector;
const vector<int> intArray = { 1, 27, -5, 72, 68 };
const vector<double> doubleArray = { 5.27, -50.05, 105.37, 45.29, 13.7};
const vector<string> stringArray = { "One", "Two", "Three", "Four", "Five" };
const vector<const char*> stringOfCharsArray = { "Seven", "Zero", "Twelve", "Eight", "Hundred" };

int maxInt;
double maxDouble;
string maxString;
const char* maxStringOfChars;

BOOST_AUTO_TEST_SUITE(FindMax_function_)

	BOOST_AUTO_TEST_CASE(returns_false_if_massive_is_empty_and_true_if_not)
	{
		BOOST_CHECK(emptyVector.empty());
		BOOST_CHECK(!FindMax(emptyVector, maxInt));
		BOOST_CHECK(FindMax(intArray, maxInt));
		BOOST_CHECK(FindMax(doubleArray, maxDouble));
		BOOST_CHECK(FindMax(stringArray, maxString));
	}

	BOOST_AUTO_TEST_CASE(does_not_change_value_of_variable_if_array_is_empty)
	{
		maxInt = 25;
		BOOST_CHECK(!FindMax(emptyVector, maxInt));
		BOOST_CHECK_EQUAL(maxInt, 25);
	}

	BOOST_AUTO_TEST_CASE(returns_max_value)
	{
		FindMax(intArray, maxInt);
		BOOST_CHECK_EQUAL(maxInt, 72);

		FindMax(doubleArray, maxDouble);
		BOOST_CHECK_EQUAL(maxDouble, 105.37);

		FindMax(stringArray, maxString);
		BOOST_CHECK_EQUAL(maxString, "Two");

		FindMax(stringOfCharsArray, maxStringOfChars);
		BOOST_CHECK_EQUAL(maxStringOfChars, "Zero");
	}

BOOST_AUTO_TEST_SUITE_END()
