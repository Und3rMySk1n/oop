#include "stdafx.h"
#include "../task2_myArray/MyArray.h"

struct MyArray_
{
	CMyArray myArray;
};

BOOST_FIXTURE_TEST_SUITE(MyArray_when_created, MyArray_)

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

	struct MyArray_filled_ : MyArray_
	{
		MyArray_filled_()
		{
			myArray.AddElement(5);
			myArray.AddElement(77);
		}
		
	};

	BOOST_FIXTURE_TEST_SUITE(MyArray_when_filled_with_elements, MyArray_filled_)

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