#include "stdafx.h"
#include "../FindMaxEx/FindMaxExUtils.cpp"

athlete Ivan { "Ivan Petrov", 186, 72 };
athlete Sergey { "Sergey Suvorov", 156, 82 };
athlete Alexey { "Alexey Kuznetsov", 178, 90 };
athlete Stepan { "Stepan Gorbunov", 192, 84 };

athlete maxAthlete;

vector<athlete> emptyAthleteArray;
vector<athlete> athleteArray = { Ivan, Sergey, Alexey, Stepan };

BOOST_AUTO_TEST_SUITE(FindMax_function_with_athlete_type_of_variables)

	BOOST_AUTO_TEST_CASE(returns_false_if_massive_is_empty_and_true_if_not)
	{
		BOOST_CHECK(emptyAthleteArray.empty());
		BOOST_CHECK(!FindMax(emptyAthleteArray, maxAthlete, LessHeight));
		BOOST_CHECK(FindMax(athleteArray, maxAthlete, LessHeight));
		BOOST_CHECK(FindMax(athleteArray, maxAthlete, LessWeight));
	}

	BOOST_AUTO_TEST_CASE(does_not_change_value_of_variable_if_array_is_empty)
	{
		maxAthlete = Sergey;
		BOOST_CHECK(!FindMax(emptyAthleteArray, maxAthlete, LessHeight));
		BOOST_CHECK(maxAthlete == Sergey);
	}

	BOOST_AUTO_TEST_CASE(returns_athlete_with_max_value_of_function_to_compare)
	{
		BOOST_CHECK(FindMax(athleteArray, maxAthlete, LessHeight));
		BOOST_CHECK(maxAthlete == Stepan);

		BOOST_CHECK(FindMax(athleteArray, maxAthlete, LessWeight));
		BOOST_CHECK(maxAthlete == Alexey);
	}	

BOOST_AUTO_TEST_SUITE_END()