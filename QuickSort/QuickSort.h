#pragma once
#include <iostream>

void printArray(int array[], size_t size)
{
	std::cout << "\n";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
}

int partition(int* array, int left, int right)
{
	// lambda
	auto swap = [](int* array, int i, int j)
	{
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	};

	int pivot = array[left + (right - left) / 2];
	while (left <= right)
	{
		// find item on the left that should be on right 
		while (array[left] < pivot) left++;
		// find item on right that should be on left
		while (array[right] > pivot) right--;

		// swap item and move indices 
		if (left <= right)
		{
			swap(array, left, right);
			left++;
			right--;
		}
	}

	return left;
}

void quicksort(int* array, int left, int right, size_t size)
{
	printArray(array, size);
	std::cout << "\n" << left << " " << right << "\n";
	int index = partition(array, left, right);
	if (left < index - 1) // sort left half
	{
		quicksort(array, left, index - 1, size);
	}
	if (index < right ) // sort right half
	{
		quicksort(array, index, right, size);
	}
}

// main entry
void quicksort(int* array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}