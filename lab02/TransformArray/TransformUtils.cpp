#include "stdafx.h"
#include "TransformUtils.h"
#include <algorithm>

bool MultiplyElementsWithMinimum(vector<double> &numbers)
{
	if (numbers.empty())
	{
		return false;		
	}

	double minElement = *min_element(numbers.begin(), numbers.end());
	transform(numbers.begin(), numbers.end(), numbers.begin(), [&minElement](double number)
	{
		return number * minElement;
	});

	return true;
}