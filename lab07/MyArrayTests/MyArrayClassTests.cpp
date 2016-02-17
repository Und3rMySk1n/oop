#include "stdafx.h"
#include "../task2_myArray/MyArray.h"

using namespace std;

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
			myArray.AddElement(123);
		}
		
	};

	BOOST_FIXTURE_TEST_SUITE(IntMyArray_when_filled_with_elements, IntMyArray_filled_)

	BOOST_AUTO_TEST_CASE(has_size_equal_number_of_elements)
	{
		BOOST_CHECK_EQUAL(myArray.GetSize(), 3);
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
		BOOST_CHECK_THROW(myArray[3] = 0, std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_be_resized_to_bigger)
	{
		myArray.Resize(10);
		BOOST_CHECK_EQUAL(myArray.GetSize(), 10);

		BOOST_CHECK_EQUAL(myArray[2], 123);
		BOOST_CHECK_EQUAL(myArray[3], 0);

		BOOST_CHECK_EQUAL(myArray[9], 0);
		BOOST_CHECK_THROW(myArray[10] = 0, std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_be_resized_to_smaller)
	{
		myArray.Resize(2);
		BOOST_CHECK_EQUAL(myArray.GetSize(), 3);
		BOOST_CHECK_EQUAL(myArray.GetCount(), 2);
		BOOST_CHECK_EQUAL(myArray[2], 0);
	}

	BOOST_AUTO_TEST_CASE(can_be_copied)
	{
		CMyArray<int> newArray;
		newArray = myArray;

		BOOST_CHECK_EQUAL(newArray.GetSize(), myArray.GetSize());
		BOOST_CHECK_EQUAL(newArray[0], myArray[0]);
		BOOST_CHECK_EQUAL(newArray[1], myArray[1]);
		BOOST_CHECK_EQUAL(newArray[2], myArray[2]);
		BOOST_CHECK_THROW(newArray[3] = 0, std::out_of_range);

		newArray.Clear();
		BOOST_CHECK_EQUAL(newArray.GetSize(), 0);
		BOOST_CHECK_EQUAL(myArray.GetSize(), 3);
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



	struct StringMyArray_
	{
		CMyArray<string> myArray;
	};

	BOOST_FIXTURE_TEST_SUITE(StringMyArray_when_created, StringMyArray_)

		BOOST_AUTO_TEST_CASE(has_size_0)
	{
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
	}

	BOOST_AUTO_TEST_CASE(can_be_filled_with_elements)
	{
		myArray.AddElement("Hello");
		myArray.AddElement("World");

		BOOST_CHECK_EQUAL(myArray[0], "Hello");
		BOOST_CHECK_EQUAL(myArray[1], "World");
		BOOST_CHECK_EQUAL(myArray.GetSize(), 2);
	}

	BOOST_AUTO_TEST_CASE(can_not_be_filled_using_index_access_operator)
	{
		BOOST_CHECK_THROW(myArray[0] = "wrong", std::out_of_range);
		BOOST_CHECK_THROW(myArray[7] = "string", std::out_of_range);
	}

	struct StringMyArray_filled_ : StringMyArray_
	{
		StringMyArray_filled_()
		{
			myArray.AddElement("One");
			myArray.AddElement("Two");
			myArray.AddElement("Three");
			myArray.AddElement("Four");
		}

	};

	BOOST_FIXTURE_TEST_SUITE(StringMyArray_when_filled_with_elements, StringMyArray_filled_)

		BOOST_AUTO_TEST_CASE(has_size_equal_number_of_elements)
	{
		BOOST_CHECK_EQUAL(myArray.GetSize(), 4);
	}

	BOOST_AUTO_TEST_CASE(allows_to_change_elements_using_index_access_operator)
	{
		BOOST_CHECK_EQUAL(myArray[0], "One");
		BOOST_CHECK_EQUAL(myArray[1], "Two");

		myArray[0] = "Zero";
		myArray[1] = "After Zero";

		BOOST_CHECK_EQUAL(myArray[0], "Zero");
		BOOST_CHECK_EQUAL(myArray[1], "After Zero");
	}

	BOOST_AUTO_TEST_CASE(does_not_allow_to_acess_to_elements_out_of_range)
	{
		BOOST_CHECK_THROW(myArray[4] = "More strings", std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_be_cleared)
	{
		myArray.Clear();
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
		BOOST_CHECK_THROW(myArray[0] = "One", std::out_of_range);
		BOOST_CHECK_THROW(string newStr = myArray[10], std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_be_constructed_as_a_copy)
	{
		CMyArray<string> copyArray(myArray);

		BOOST_CHECK_EQUAL(copyArray.GetSize(), 4);
		BOOST_CHECK_EQUAL(copyArray[0], "One");
		BOOST_CHECK_EQUAL(copyArray[1], "Two");
		BOOST_CHECK_EQUAL(copyArray[2], "Three");
		BOOST_CHECK_EQUAL(copyArray[3], "Four");

		myArray.Clear();
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
		BOOST_CHECK_EQUAL(copyArray.GetSize(), 4);
		BOOST_CHECK_EQUAL(copyArray[0], "One");
		BOOST_CHECK_EQUAL(copyArray[1], "Two");
		BOOST_CHECK_EQUAL(copyArray[2], "Three");
		BOOST_CHECK_EQUAL(copyArray[3], "Four");
	}

	BOOST_AUTO_TEST_CASE(can_be_copied)
	{
		CMyArray<string> copyArray;
		copyArray = myArray;

		BOOST_CHECK_EQUAL(copyArray.GetSize(), 4);
		BOOST_CHECK_EQUAL(copyArray[0], "One");
		BOOST_CHECK_EQUAL(copyArray[1], "Two");
		BOOST_CHECK_EQUAL(copyArray[2], "Three");
		BOOST_CHECK_EQUAL(copyArray[3], "Four");

		myArray.Clear();
		BOOST_CHECK_EQUAL(myArray.GetSize(), 0);
		BOOST_CHECK_EQUAL(copyArray.GetSize(), 4);
		BOOST_CHECK_EQUAL(copyArray[0], "One");
		BOOST_CHECK_EQUAL(copyArray[1], "Two");
		BOOST_CHECK_EQUAL(copyArray[2], "Three");
		BOOST_CHECK_EQUAL(copyArray[3], "Four");
	}

	BOOST_AUTO_TEST_CASE(can_be_resized_to_bigger)
	{
		myArray.Resize(6);
		BOOST_CHECK_EQUAL(myArray[0], "One");
		BOOST_CHECK_EQUAL(myArray[1], "Two");
		BOOST_CHECK_EQUAL(myArray[2], "Three");
		BOOST_CHECK_EQUAL(myArray[3], "Four");
		BOOST_CHECK_EQUAL(myArray[4], "");
		BOOST_CHECK_EQUAL(myArray[5], "");
		BOOST_CHECK_THROW(myArray[6], std::out_of_range);
		BOOST_CHECK_EQUAL(myArray.GetSize(), 6);
	}

	BOOST_AUTO_TEST_CASE(can_be_resized_to_smaller)
	{
		myArray.Resize(2);
		BOOST_CHECK_EQUAL(myArray[0], "One");
		BOOST_CHECK_EQUAL(myArray[1], "Two");
		BOOST_CHECK_EQUAL(myArray[2], "");
		BOOST_CHECK_EQUAL(myArray[3], "");
		BOOST_CHECK_THROW(myArray[4], std::out_of_range);
		BOOST_CHECK_EQUAL(myArray.GetSize(), 4);
		BOOST_CHECK_EQUAL(myArray.GetCount(), 2);

		myArray.AddElement("Three");
		BOOST_CHECK_EQUAL(myArray[2], "Three");

		myArray.AddElement("Four");
		BOOST_CHECK_EQUAL(myArray[3], "Four");

		myArray.AddElement("Five");
		BOOST_CHECK_EQUAL(myArray[4], "Five");
		BOOST_CHECK_EQUAL(myArray.GetSize(), 5);
	}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()