#include "stdafx.h"
#include "../Solve3/Solve3Utils.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Solve3_function)

BOOST_AUTO_TEST_CASE(throws_exception_when_first_coefficient_is_0)
	{
		BOOST_CHECK_THROW(Solve3(0.0, 5.1, 19.20, 3.7), invalid_argument);
	}

BOOST_AUTO_TEST_CASE(can_have_3_real_roots)
{
	EquationRoots3 result = Solve3(4.0, -19.0, 19.0, 6);

	BOOST_CHECK_EQUAL(result.numRoots, 3);
	BOOST_CHECK_CLOSE(result.roots[0], -0.25, 1e-10);
	BOOST_CHECK_CLOSE(result.roots[1], 3, 1e-10);
	BOOST_CHECK_CLOSE(result.roots[2], 2, 1e-10);
}

BOOST_AUTO_TEST_CASE(can_have_1_real_root)
{
	EquationRoots3 result = Solve3(5.0, 10.0, 7.0, 2.0);

	BOOST_CHECK_EQUAL(result.numRoots, 1);
	BOOST_CHECK_CLOSE(result.roots[0], -1, 10);
}

BOOST_AUTO_TEST_SUITE_END()