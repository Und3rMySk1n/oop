#include "stdafx.h"
#include "../TransformArray/TransformUtils.h"


BOOST_AUTO_TEST_SUITE(multiply_with_minimal_element)
    
	BOOST_AUTO_TEST_CASE(returns_false_with_empty_vector)
	{
		vector<double> originalVector;
		MultiplyElementsWithMinimum(originalVector);

		BOOST_CHECK(originalVector.empty());
	}

	BOOST_AUTO_TEST_CASE(returns_right_result_with_positive_minimum)
	{
		vector<double> originalVector = {0.1, 15.0123, 100.5};
		vector<double> resultVector = {0.1 * 0.1, 15.0123 * 0.1, 100.5  * 0.1};
		MultiplyElementsWithMinimum(originalVector);

		BOOST_CHECK(originalVector == resultVector);
	}

	BOOST_AUTO_TEST_CASE(returns_right_result_with_negative_minimum)
	{
		vector<double> originalVector = {-10.215, 1589.1001, -5.011};
		vector<double> resultVector = {-10.215 * (-10.215), 1589.1001 * (-10.215), -5.011  * (-10.215)};
		MultiplyElementsWithMinimum(originalVector);

		BOOST_CHECK(originalVector == resultVector);
	}	

	BOOST_AUTO_TEST_CASE(returns_right_result_with_zero_minimum)
	{
		vector<double> originalVector = { 125.11, 30, 0 };
		vector<double> resultVector = { 0, 0, 0 };
		MultiplyElementsWithMinimum(originalVector);

		BOOST_CHECK(originalVector == resultVector);
	}

BOOST_AUTO_TEST_SUITE_END()