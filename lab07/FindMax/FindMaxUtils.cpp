#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;


template<typename T>
bool FindMax(vector<T> const &arr, T &maxValue)
{
	if (!arr.empty())
	{
		maxValue = arr.at(0);
		for (auto & item : arr)
		{
			if (item > maxValue)
			{
				maxValue = item;
			}
		}
		return true;
	}

	return false;
}

template<>
bool FindMax<const char *>(vector<const char*> const &arr, const char* &maxValue)
{
	if (!arr.empty())
	{
		maxValue = arr.at(0);
		for (auto & item : arr)
		{
			if (*item > *maxValue)
			{
				maxValue = item;
			}
		}
		return true;
	}

	return false;
}