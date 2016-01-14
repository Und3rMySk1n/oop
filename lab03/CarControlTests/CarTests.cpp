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


struct car_with_engine_on_ : CarFixture
{
	car_with_engine_on_()
	{
		car.TurnOnEngine();
	}
};

// заведенный автомобиль
BOOST_FIXTURE_TEST_SUITE(car_with_engine_on, car_with_engine_on_)

	// может быть переключен на первую передачу
	BOOST_AUTO_TEST_CASE(gear_can_be_shifted_to_first)
	{
		BOOST_CHECK(car.SetGear(Gear::first));
		BOOST_CHECK(car.GetGear() == Gear::first);
	}

	// может быть переключен на заднюю передачу
	BOOST_AUTO_TEST_CASE(gear_can_be_shifted_to_reverse)
	{
		BOOST_CHECK(car.SetGear(Gear::reverse));
		BOOST_CHECK(car.GetGear() == Gear::reverse);
	}

	// может быть переключен на первую, а затем на заднюю передачу
	BOOST_AUTO_TEST_CASE(gear_can_be_shifted_to_first_and_then_to_reverse)
	{
		BOOST_CHECK(car.SetGear(Gear::first));
		BOOST_CHECK(car.GetGear() == Gear::first);

		BOOST_CHECK(car.SetGear(Gear::reverse));
		BOOST_CHECK(car.GetGear() == Gear::reverse);
	}

	// не может быть переключен на передачу больше первой
	BOOST_AUTO_TEST_CASE(gear_can_not_be_shifted_to_more_than_first_gear)
	{
		BOOST_CHECK(!car.SetGear(Gear::second));	
		BOOST_CHECK(car.GetGear() == Gear::neutral);

		BOOST_CHECK(!car.SetGear(Gear::third));
		BOOST_CHECK(car.GetGear() == Gear::neutral);

		BOOST_CHECK(!car.SetGear(Gear::fourth));
		BOOST_CHECK(car.GetGear() == Gear::neutral);

		BOOST_CHECK(!car.SetGear(Gear::fifth));
		BOOST_CHECK(car.GetGear() == Gear::neutral);
	}

	struct on_reverse_gear_ : car_with_engine_on_
	{
		on_reverse_gear_()
		{
			car.SetGear(Gear::reverse);
		}
	};

	// на задней передаче
	BOOST_FIXTURE_TEST_SUITE(on_reverse_gear, on_reverse_gear_)

		// имеет нулевую скорость
		BOOST_AUTO_TEST_CASE(has_speed_0)
		{
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		}

		// может разогнаться до 20 км в час
		BOOST_AUTO_TEST_CASE(can_get_speed_up_to_20)
		{
			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);

			BOOST_CHECK(car.SetSpeed(12));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 12);

			BOOST_CHECK(car.SetSpeed(20));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 20);
		}

		// не может разогнаться больше 20 км в час или меньше 0
		BOOST_AUTO_TEST_CASE(can_not_get_speed_up_to_more_than_20_or_less_than_0)
		{
			BOOST_CHECK(!car.SetSpeed(-10));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);

			BOOST_CHECK(!car.SetSpeed(50));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		}

		// может переключиться на нейтральную передачу
		BOOST_AUTO_TEST_CASE(can_shift_to_neutral_gear)
		{
			car.SetSpeed(7);

			BOOST_CHECK(car.SetGear(Gear::neutral));
			BOOST_CHECK(car.GetGear() == Gear::neutral);
		}

		// при переключении на нейтральную передачу не переключается на первую до остановки
		BOOST_AUTO_TEST_CASE(can_shift_to_first_gear_through_neutral_only_after_stop)
		{
			car.SetSpeed(7);

			BOOST_CHECK(car.SetGear(Gear::neutral));
			BOOST_CHECK(car.GetGear() == Gear::neutral);

			BOOST_CHECK(!car.SetGear(Gear::first));

			car.SetSpeed(0);
			BOOST_CHECK(car.SetGear(Gear::first));
			BOOST_CHECK(car.GetGear() == Gear::first);
		}

		// может переключиться на заднюю передачу
		BOOST_AUTO_TEST_CASE(can_shift_to_reverse_gear)
		{
			car.SetSpeed(7);

			BOOST_CHECK(car.SetGear(Gear::reverse));
			BOOST_CHECK(car.GetGear() == Gear::reverse);
		}

		// может переключиться на первую передачу при нулевой скорости
		BOOST_AUTO_TEST_CASE(can_shift_to_first_gear_with_speed_0)
		{
			BOOST_CHECK(car.SetGear(Gear::first));
			BOOST_CHECK(car.GetGear() == Gear::first);
		}

		// не может переключиться на передачу больше нейтральной на скорости больше 0
		BOOST_AUTO_TEST_CASE(can_not_shift_to_reverse_on_speed_more_than_0)
		{
			car.SetSpeed(10);

			BOOST_CHECK(!car.SetGear(Gear::first));
			BOOST_CHECK(car.GetGear() == Gear::reverse);

			BOOST_CHECK(!car.SetGear(Gear::second));
			BOOST_CHECK(car.GetGear() == Gear::reverse);

			BOOST_CHECK(!car.SetGear(Gear::third));
			BOOST_CHECK(car.GetGear() == Gear::reverse);

			BOOST_CHECK(!car.SetGear(Gear::fourth));
			BOOST_CHECK(car.GetGear() == Gear::reverse);

			BOOST_CHECK(!car.SetGear(Gear::fifth));
			BOOST_CHECK(car.GetGear() == Gear::reverse);
		}

	BOOST_AUTO_TEST_SUITE_END();

	struct on_first_gear_ : car_with_engine_on_
	{
		on_first_gear_()
		{
			car.SetGear(Gear::first);
		}
	};

	// на первой передаче
	BOOST_FIXTURE_TEST_SUITE(on_first_gear, on_first_gear_)

		// может разогнаться до 30 км в час
		BOOST_AUTO_TEST_CASE(can_get_speed_up_to_30)
		{
			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);

			BOOST_CHECK(car.SetSpeed(25));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 25);

			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 30);
		}

		// не может разогнаться больше 30 км в час или меньше 0
		BOOST_AUTO_TEST_CASE(can_not_get_speed_up_to_more_than_30_or_less_than_0)
		{
			BOOST_CHECK(!car.SetSpeed(-10));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);

			BOOST_CHECK(!car.SetSpeed(50));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		}
		
		// может переключиться на нейтральную передачу на скорости
		BOOST_AUTO_TEST_CASE(can_shift_to_neutral_gear_with_speed_more_than_0)
		{
			car.SetSpeed(7);

			BOOST_CHECK(car.SetGear(Gear::neutral));
			BOOST_CHECK(car.GetGear() == Gear::neutral);
		}

		// может переключиться на заднюю передачу
		BOOST_AUTO_TEST_CASE(can_shift_to_reverse_gear_with_speed_0)
		{
			car.SetSpeed(0);

			BOOST_CHECK(car.SetGear(Gear::reverse));
			BOOST_CHECK(car.GetGear() == Gear::reverse);
		}

		// может переключиться на вторую передачу при скорости от 20
		BOOST_AUTO_TEST_CASE(can_shift_to_second_gear_with_speed_more_than_20)
		{
			car.SetSpeed(20);

			BOOST_CHECK(car.SetGear(Gear::second));
			BOOST_CHECK(car.GetGear() == Gear::second);
		}

		// не может переключиться на вторую передачу при скорости меньше 20
		BOOST_AUTO_TEST_CASE(can_not_shift_to_second_gear_with_speed_less_than_20)
		{
			car.SetSpeed(10);

			BOOST_CHECK(!car.SetGear(Gear::second));
			BOOST_CHECK(car.GetGear() == Gear::first);
		}

	BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE_END();