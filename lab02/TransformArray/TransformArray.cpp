// TransformArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TransformUtils.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	if (numbers.empty())
	{
		cout << "No numbers entered." << endl;
		return 1;
	}

	MultiplyElementsWithMinimum(numbers);
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout << fixed << setprecision(3), " "));

	return 0;
}

