#include "stdafx.h"
#include "../Dictionary/DictionaryUtils.h"
#include <string>

BOOST_AUTO_TEST_SUITE(dictionary_tests)
    
    // ���������� ������ ������, ���� ������� ������
	BOOST_AUTO_TEST_CASE(returns_empty_string_if_dictionary_is_empty)
	{
		std::map<std::string, std::string> testDictionary;
		std::string sampleString = "Test";
		std::string resultString = GetTranslation(testDictionary, sampleString);

		BOOST_CHECK_EQUAL(resultString, "");
	}

	// ���������� �������, ���� ����� ���� � �������
	BOOST_AUTO_TEST_CASE(returns_translation_if_word_is_in_dictionary)
	{
		std::map<std::string, std::string> testDictionary;
		testDictionary.insert(std::pair<std::string, std::string>("cat", "�����"));

		std::string sampleString = "cat";
		std::string resultString = GetTranslation(testDictionary, sampleString);

		BOOST_CHECK_EQUAL(resultString, "�����");
	}

	// ��������� � ������� ����� � ���������
	BOOST_AUTO_TEST_CASE(adds_word_and_translation_in_dictionary)
	{
		std::map<std::string, std::string> testDictionary;		

		std::string word = "duck";
		std::string translate = "����";
		AddTranslation(testDictionary, word, translate);

		std::string resultString = GetTranslation(testDictionary, "duck");

		BOOST_CHECK_EQUAL(resultString, "����");
	}

BOOST_AUTO_TEST_SUITE_END()