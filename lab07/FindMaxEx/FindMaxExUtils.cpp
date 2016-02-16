#include "stdafx.h"
#include <iostream>

using namespace std;

struct athlete
{
	string name;
	unsigned int height;
	unsigned int weight;
};

bool LessWeight(const athlete &athlete1, const athlete &athlete2)
{
	return (athlete1.weight < athlete2.weight);
}

bool LessHeight(const athlete &athlete1, const athlete &athlete2)
{
	return (athlete1.height < athlete2.height);
}

bool operator == (athlete const & athlete1, athlete const & athlete2)
{
	return (athlete1.name == athlete2.name) && (athlete1.height == athlete2.height)
		&& (athlete1.weight == athlete2.weight);
}

template<typename T, typename Less>
bool FindMax(vector<T> const &arr, T &maxValue, Less const &less)
{
	if (!arr.empty())
	{
		maxValue = arr.at(0);
		for (auto & item : arr)
		{
			if (less(maxValue, item))
			{
				maxValue = item;
			}
		}
		return true;
	}

	return false;
}