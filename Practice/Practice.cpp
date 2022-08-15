// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int BinarySearchIterative(int arr[], int size, int val )
{
	int low = 0;
	int high = size;

	int mid = size / 2;

	while (mid >= low && mid <= high )
	{
		if (val == arr[mid]) return mid;
		if (mid == low || mid == high) return -1;

		if (val <= arr[mid])
			high = mid;
		else
			low = mid;

		mid = (high + low) / 2;
	}

	return -1;
}


void testBSearch()
{
	int arr[] = { 1, 2, 8, 9, 12, 13, 15 };
	int res = BinarySearchIterative(arr, 7, 20);
	_ASSERTE(res == -1);
}

int main()
{
	testBSearch();
    std::cout << "Hello World!\n";
}

