#include "stdafx.h"
#include "../HTMLEncode/HTMLUtils.h"


BOOST_AUTO_TEST_SUITE(encodes_html_string)

	BOOST_AUTO_TEST_CASE(returns_empty_string_if_original_string_is_empty)
	{
		std::string originalString;
		std::string encodedString = HtmlEncode(originalString);

		BOOST_CHECK(encodedString.empty());
	}

	BOOST_AUTO_TEST_CASE(returns_original_string_if_it_contains_no_special_symbols)
	{
		std::string originalString = "Sample string with no special chars #1";
		std::string encodedString = HtmlEncode(originalString);

		BOOST_CHECK_EQUAL(originalString, encodedString);
	}

	BOOST_AUTO_TEST_CASE(correctly_encodes_quot)
	{
		std::string originalString = "Sample string with \"a quot\"";
		std::string encodedString = HtmlEncode(originalString);
		std::string rightResultString = "Sample string with &quot;a quot&quot;";

		BOOST_CHECK_EQUAL(encodedString, rightResultString);
	}

	BOOST_AUTO_TEST_CASE(correctly_encodes_apostrophe)
	{
		std::string originalString = "Another sample string with 'this' apostrophe";
		std::string encodedString = HtmlEncode(originalString);
		std::string rightResultString = "Another sample string with &apos;this&apos; apostrophe";

		BOOST_CHECK_EQUAL(encodedString, rightResultString);
	}

	BOOST_AUTO_TEST_CASE(correctly_encodes_less_and_more)
	{
		std::string originalString = "<title>Samle title</title>";
		std::string encodedString = HtmlEncode(originalString);
		std::string rightResultString = "&lt;title&gt;Samle title&lt;/title&gt;";

		BOOST_CHECK_EQUAL(encodedString, rightResultString);
	}

	BOOST_AUTO_TEST_CASE(correctly_encodes_ampersand)
	{
		std::string originalString = "Some text with this & ampersand";
		std::string encodedString = HtmlEncode(originalString);
		std::string rightResultString = "Some text with this &amp; ampersand";

		BOOST_CHECK_EQUAL(encodedString, rightResultString);
	}

	BOOST_AUTO_TEST_CASE(correctly_encodes_combined_html_string)
	{
		std::string originalString = "<div class=\"main\"><p>Desperate 'times' & desperate 'measures'</p></div>";
		std::string encodedString = HtmlEncode(originalString);
		std::string rightResultString = "&lt;div class=&quot;main&quot;&gt;&lt;p&gt;Desperate &apos;times&apos; &amp; desperate &apos;measures&apos;&lt;/p&gt;&lt;/div&gt;";

		BOOST_CHECK_EQUAL(encodedString, rightResultString);
	}

BOOST_AUTO_TEST_SUITE_END()