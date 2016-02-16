#include "stdafx.h"
#include "../task2_myArray/MyArray.h"

struct IntMyArray_
{
	CMyArray<int> myArray;
};

BOOST_FIXTURE_TEST_SUITE(IntMyArray_when_created, IntMyArray_)

	BOOST_AUTO_TEST_CASE(has_size_0)
	{
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
	}

	BOOST_AUTO_TEST_CASE(can_be_filled_with_elements)
	{
		myArray.AddElement(100);
		myArray.AddElement(-20);

		BOOST_CHECK_EQUAL(myArray[0], 100);
		BOOST_CHECK_EQUAL(myArray[1], -20);
		BOOST_CHECK_EQUAL(myArray.GetSize(), 2);
	}

	BOOST_AUTO_TEST_CASE(can_not_be_filled_using_index_access_operator)
	{
		BOOST_CHECK_THROW(myArray[0] = 100, std::out_of_range);
		BOOST_CHECK_THROW(myArray[7] = 20, std::out_of_range);
	}

	struct IntMyArray_filled_ : IntMyArray_
	{
		IntMyArray_filled_()
		{
			myArray.AddElement(5);
			myArray.AddElement(77);
		}
		
	};

	BOOST_FIXTURE_TEST_SUITE(IntMyArray_when_filled_with_elements, IntMyArray_filled_)

	BOOST_AUTO_TEST_CASE(has_size_equal_number_of_elements)
	{
		BOOST_CHECK_EQUAL(myArray.GetSize(), 2);
	}

	BOOST_AUTO_TEST_CASE(allows_to_change_elements_using_index_access_operator)
	{
		BOOST_CHECK_EQUAL(myArray[0], 5);
		BOOST_CHECK_EQUAL(myArray[1], 77);

		myArray[0] = 72;
		myArray[1] = 35;

		BOOST_CHECK_EQUAL(myArray[0], 72);
		BOOST_CHECK_EQUAL(myArray[1], 35);
	}

	BOOST_AUTO_TEST_CASE(does_not_allow_to_acess_to_elements_out_of_range)
	{
		BOOST_CHECK_THROW(myArray[2] = 0, std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_be_cleared)
	{
		myArray.Clear();
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
		BOOST_CHECK_THROW(myArray[0] = 5, std::out_of_range);
		BOOST_CHECK_THROW(int x = myArray[0], std::out_of_range);
	}

	BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE_END()

	struct DoubleMyArray_
	{
		CMyArray<double> myArray;
	};

	BOOST_FIXTURE_TEST_SUITE(DoubleMyArray_when_created, DoubleMyArray_)

		BOOST_AUTO_TEST_CASE(has_size_0)
		{
			BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
		}

	BOOST_AUTO_TEST_CASE(can_be_filled_with_elements)
	{
		myArray.AddElement(25.1009);
		myArray.AddElement(-15.005);

		BOOST_CHECK_EQUAL(myArray[0], 25.1009);
		BOOST_CHECK_EQUAL(myArray[1], -15.005);
		BOOST_CHECK_EQUAL(myArray.GetSize(), 2);
	}

	BOOST_AUTO_TEST_CASE(can_not_be_filled_using_index_access_operator)
	{
		BOOST_CHECK_THROW(myArray[0] = 10.06, std::out_of_range);
		BOOST_CHECK_THROW(myArray[7] = 0.006, std::out_of_range);
	}

	struct DoubleMyArray_filled_ : DoubleMyArray_
	{
		DoubleMyArray_filled_()
		{
			myArray.AddElement(5.27);
			myArray.AddElement(1986.29);
		}

	};

	BOOST_FIXTURE_TEST_SUITE(DoubleMyArray_when_filled_with_elements, DoubleMyArray_filled_)

		BOOST_AUTO_TEST_CASE(has_size_equal_number_of_elements)
	{
		BOOST_CHECK_EQUAL(myArray.GetSize(), 2);
	}

	BOOST_AUTO_TEST_CASE(allows_to_change_elements_using_index_access_operator)
	{
		BOOST_CHECK_EQUAL(myArray[0], 5.27);
		BOOST_CHECK_EQUAL(myArray[1], 1986.29);

		myArray[0] = 27.5;
		myArray[1] = 29.1986;

		BOOST_CHECK_EQUAL(myArray[0], 27.5);
		BOOST_CHECK_EQUAL(myArray[1], 29.1986);
	}

	BOOST_AUTO_TEST_CASE(does_not_allow_to_acess_to_elements_out_of_range)
	{
		BOOST_CHECK_THROW(myArray[2] = 0.56, std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_be_cleared)
	{
		myArray.Clear();
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
		BOOST_CHECK_THROW(myArray[0] = 5.26, std::out_of_range);
		BOOST_CHECK_THROW(double x = myArray[10], std::out_of_range);
	}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()