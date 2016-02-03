#include "stdafx.h"
#include "TransformUtils.h"
#include <algorithm>

void MultiplyElementsWithMinimum(vector<double> &numbers)
{
	if (!numbers.empty())
	{
		double minElement = *min_element(numbers.begin(), numbers.end());
		transform(numbers.begin(), numbers.end(), numbers.begin(), [&minElement](double number)
		{
			return number * minElement;
		});
	}
}