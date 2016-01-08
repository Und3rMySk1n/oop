#include "stdafx.h"
#include "../CarControl/Car.h"

using Gear = CCar::Gear;
using Direction = CCar::Direction;

struct CarFixture
{
	CCar car;
};

// автомобиль
BOOST_FIXTURE_TEST_SUITE(car, CarFixture)

    // сначала выключен
	BOOST_AUTO_TEST_CASE(engine_is_off)
	{
		BOOST_CHECK(!car.IsEngineOn());
	}

    // находится на нейтральной передаче
	BOOST_AUTO_TEST_CASE(gear_is_neutral)
	{
		BOOST_CHECK(car.GetGear() == Gear::neutral);
	}

    // имеет нулевую скорость
	BOOST_AUTO_TEST_CASE(speed_is_0)
	{
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	}

	// не имеет направления движения (стоит)
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

	// после включения двигателя
	BOOST_FIXTURE_TEST_SUITE(after_engine_on, after_engine_on_)

		// двигатель включен
		BOOST_AUTO_TEST_CASE(engine_is_on)
		{
			BOOST_CHECK(car.IsEngineOn());
		}

		// находится на нейтральной передаче
		BOOST_AUTO_TEST_CASE(gear_is_neutral)
		{
			BOOST_CHECK(car.GetGear() == Gear::neutral);
		}

		// имеет нулевую скорость
		BOOST_AUTO_TEST_CASE(speed_is_0)
		{
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		}

		// не имеет направления движения (стоит)
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

	// после повторного включения
	BOOST_FIXTURE_TEST_SUITE(after_engine_on_twice, after_engine_on_twice_)

		// двигатель включен
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

	// после выключения
	BOOST_FIXTURE_TEST_SUITE(after_engine_off, after_engine_off_)

		// двигатель включен
		BOOST_AUTO_TEST_CASE(engine_is_off)
		{
			BOOST_CHECK(!car.IsEngineOn());
		}

	BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE_END();