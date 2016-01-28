#include "stdafx.h"
#include <stdio.h>
#include <iostream>

#define _USE_MATH_DEFINES
#include "../Cylinder.h"
#include <math.h>


struct Cylinder_
{
	const double expectedRadius = 9.7;
	const double expectedHeight = 5.8;

	const double expectedDensity = 13.2;
	const double expectedVolume = 1714.43622;

	const CCylinder cylinder;
	Cylinder_()
		: cylinder(expectedDensity, expectedRadius, expectedHeight)
	{}
};
// Цилиндр
BOOST_FIXTURE_TEST_SUITE(Cylinder, Cylinder_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&cylinder));
}
// имеет радиус
BOOST_AUTO_TEST_CASE(has_a_radius)
{
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), expectedRadius);
}
// имеет высоту
BOOST_AUTO_TEST_CASE(has_a_height)
{
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), expectedHeight);
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).GetDensity(), expectedDensity);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetVolume(), expectedVolume, 1e-7);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_a_mass)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetMass(), expectedVolume * expectedDensity, 1e-7);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Cylinder:
	density = 13.2
	volume = 1714.436226
	mass = 22630.55818
	radius = 9.7
	height = 5.8
)";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()