#include "stdafx.h"
#include "../CarControl/Car.h"

using Gear = CCar::Gear;

struct CarFixture
{
	CCar car;
};

// ����������
BOOST_FIXTURE_TEST_SUITE(car, CarFixture)

    // ������� ��������
	BOOST_AUTO_TEST_CASE(engine_is_off)
	{
		BOOST_CHECK(!car.IsEngineOn());
	}

    // ��������� �� ����������� ��������
	BOOST_AUTO_TEST_CASE(gear_is_neutral)
	{
		BOOST_CHECK(car.GetGear() == Gear::neutral);
	}

    // ����� ������� ��������
	BOOST_AUTO_TEST_CASE(speed_is_0)
	{
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	}
	 
BOOST_AUTO_TEST_SUITE_END();