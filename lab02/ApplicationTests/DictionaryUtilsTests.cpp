#include "stdafx.h"
#include "../Dictionary/DictionaryUtils.h"
#include <string>

using namespace std;

struct DictionaryFixture
{
	map<string, string> testDictionary;
};

// �������
BOOST_FIXTURE_TEST_SUITE(dictionary_tests, DictionaryFixture)
    
    // ���������� ������ ������, ���� ������� ������
	BOOST_AUTO_TEST_CASE(returns_empty_string_if_dictionary_is_empty)
	{					
		string resultString = GetTranslation(testDictionary, "Test");
		BOOST_CHECK_EQUAL(resultString, "");		
	}

	// �� ������ ������ ������� ��� ���������
	BOOST_AUTO_TEST_CASE(does_not_change_dictionary_on_request)
	{
		string resultString = GetTranslation(testDictionary, "Test string");
		BOOST_CHECK(testDictionary.empty());
	}

	// ��������� � ������� ����� � ���������
	BOOST_AUTO_TEST_CASE(adds_word_and_translation_in_dictionary)
	{
		AddTranslation(testDictionary, "duck", "����");
		BOOST_CHECK(!testDictionary.empty());

		string resultString = GetTranslation(testDictionary, "duck");
		BOOST_CHECK_EQUAL(resultString, "����");
	}	

		struct dictionary_with_word_ : DictionaryFixture
		{
			dictionary_with_word_()
			{
				AddTranslation(testDictionary, "dog", "������");
			}
		};

		// ������� � ���������
		BOOST_FIXTURE_TEST_SUITE(dictionary_with_word, dictionary_with_word_)

			// ��������
			BOOST_AUTO_TEST_CASE(not_empty)
			{
				BOOST_CHECK(!testDictionary.empty());
			}
			
			// ���������� ������� �����
			BOOST_AUTO_TEST_CASE(returns_translation)
			{				
				string resultString = GetTranslation(testDictionary, "dog");
				BOOST_CHECK_EQUAL(resultString, "������");
			}

		BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()