// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "QuickSort.h"

void testQuickSort()
{
	int array[] = { 1,4,5,2,8,9,3,1 };
	int size = _countof(array);
	std::cout << "Initial array:";

	printArray(array, size);
	quicksort(array, size);
	std::cout << "\nAfter sort:";
	printArray(array, size);
}

int main()
{
	testQuickSort();
}

