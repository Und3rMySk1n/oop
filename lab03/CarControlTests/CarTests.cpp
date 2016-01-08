#include "stdafx.h"
#include "../CarControl/Car.h"

using Gear = CCar::Gear;
using Direction = CCar::Direction;

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

	// �� ����� ����������� �������� (�����)
	BOOST_AUTO_TEST_CASE(doesnt_have_direction)
	{
		BOOST_CHECK(car.GetDirection() == Direction::stop);
	}

	struct after_engine_on_ : CarFixture
	{
		after_engine_on_()
		{
			car.TurnOnEngine();
		}
	};

	// ����� ��������� ���������
	BOOST_FIXTURE_TEST_SUITE(after_engine_on, after_engine_on_)

		// ��������� �������
		BOOST_AUTO_TEST_CASE(engine_is_on)
		{
			BOOST_CHECK(car.IsEngineOn());
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

		// �� ����� ����������� �������� (�����)
		BOOST_AUTO_TEST_CASE(doesnt_have_direction)
		{
			BOOST_CHECK(car.GetDirection() == Direction::stop);
		}

	BOOST_AUTO_TEST_SUITE_END();

	struct after_engine_on_twice_ : after_engine_on_
	{
		after_engine_on_twice_()
		{
			car.TurnOnEngine();
		}
	};

	// ����� ���������� ���������
	BOOST_FIXTURE_TEST_SUITE(after_engine_on_twice, after_engine_on_twice_)

		// ��������� �������
		BOOST_AUTO_TEST_CASE(engine_is_on)
		{
			BOOST_CHECK(car.IsEngineOn());
		}

	BOOST_AUTO_TEST_SUITE_END();

	struct after_engine_off_ : after_engine_on_twice_
	{
		after_engine_off_()
		{
			car.TurnOffEngine();
		}
	};

	// ����� ����������
	BOOST_FIXTURE_TEST_SUITE(after_engine_off, after_engine_off_)

		// ��������� �������
		BOOST_AUTO_TEST_CASE(engine_is_off)
		{
			BOOST_CHECK(!car.IsEngineOn());
		}

	BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE_END();