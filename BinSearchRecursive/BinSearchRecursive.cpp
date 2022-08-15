// BinSearchRecursive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

const int NOT_FOUND = -1;

int _binSearch(vector<int> array, int start, int end, int searchVal)
{
	if (end < start) return NOT_FOUND;

	int mid = (start + end) / 2;
	if (searchVal == array[mid]) return mid;

	if (searchVal < array[mid]) return _binSearch(array, start, mid - 1, searchVal);
	else return _binSearch(array, mid + 1, end, searchVal);
}

int binSearch(vector<int> array, int searchVal)
{
	return _binSearch(array, 0, array.size() - 1, searchVal);
}

int binSearchIter(vector<int> array, int searchVal)
{
	int size = array.size();
	int start = 0;
	int end = size - 1;

	while (true)
	{
		if (end <= start) return NOT_FOUND;
		int mid = (start + end) / 2;
		if (searchVal == array[mid]) return mid;
		if (searchVal < array[mid])
		{
			end = mid - 1;
			continue;
		}
		else
		{
			start = mid + 1;
			continue;
		}
	}

	return NOT_FOUND;
}

int binSearchIter1(vector<int> array, int searchVal)
{
	int size = array.size();
	int start{ 0 };
	int end = size - 1;

	while (true)
	{
		if (end <= start) return NOT_FOUND;
		int mid = (start + end) / 2;
		if (searchVal == array[mid]) return mid;
		else if (searchVal > array[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

	}
	return NOT_FOUND;
}


void testSearch()
{
	vector<int> array{ 1, 3, 5, 9, 20, 101, 122, 144, 177, 200, 340, 534 };
	_ASSERTE(3 == binSearchIter1(array, 9));
	_ASSERTE(NOT_FOUND == binSearchIter(array, 99));
	_ASSERTE(NOT_FOUND == binSearchIter(array, 0));

}

int main()
{
	testSearch();
    //std::cout << "Hello World!\n";
}

