#include "stdafx.h"
#include <stdio.h>
#include <iostream>

#include "../UserInterface.h"

using namespace std;

struct BodyVector
{
	BodyPtrVector bodiesVector;
};

// Вектор тел
BOOST_FIXTURE_TEST_SUITE(body_vector, BodyVector)

	// изначально пустой 
	BOOST_AUTO_TEST_CASE(is_empty_when_created)
	{
		BOOST_CHECK(bodiesVector.empty());
	}

	// не добавляет тело при неправильном синтаксисе команды
	BOOST_AUTO_TEST_CASE(does_not_add_body_after_wrong_command)
	{
		string command = "create sphere 1";
		ProcessCommand(command, bodiesVector);		

		BOOST_CHECK(bodiesVector.empty());
	}

	// содержит тело при его добавлении 
	BOOST_AUTO_TEST_CASE(contains_body_after_adding)
	{
		string command = "create sphere 1 2";
		ProcessCommand(command, bodiesVector);

		BodyPtr sphere = make_shared<CSphere>(1, 2);

		BOOST_CHECK(!bodiesVector.empty());
		BOOST_CHECK(sphere->ToString() == bodiesVector.at(0)->ToString());
	}

		struct BodyVectorWithObjects_ : BodyVector
		{
			BodyVectorWithObjects_()
			{
				BodyPtr sphere = make_shared<CSphere>(1100, 2.25);
				BodyPtr cone = make_shared<CCone>(1200, 5, 2.5);
				BodyPtr cylinder = make_shared<CCylinder>(1350, 7, 3);
				BodyPtr parallelepiped = make_shared<CParallelepiped>(1500, 4.5, 2.5, 1.75);

				bodiesVector.push_back(sphere);
				bodiesVector.push_back(cone);
				bodiesVector.push_back(cylinder);
				bodiesVector.push_back(parallelepiped);
			}			
		};

		BOOST_FIXTURE_TEST_SUITE(with_objects_, BodyVectorWithObjects_)

			BOOST_AUTO_TEST_CASE(returns_body_with_max_weight)
			{				
				BodyPtr maxBody = GetHeaviestBody(bodiesVector);

				BOOST_CHECK(maxBody == bodiesVector.at(2)); // cylinder
			}

			BOOST_AUTO_TEST_CASE(returns_body_with_min_weight_in_water)
			{
				BodyPtr maxBody = GetLightestInWater(bodiesVector);

				BOOST_CHECK(maxBody == bodiesVector.at(0)); // sphere
			}

		BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()