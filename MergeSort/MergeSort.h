#pragma once


void printArray(int array[], int size)
{
	std::cout << "\n";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
}

void merge(int array[], int* phelper, int low, int middle, int high, int size)
{
	for (int i = low; i <= high; i++)
	{
		phelper[i] = array[i];
	}

	int helperLeft = low;
	int helperRight = middle + 1;
	int current = low;
	// iterate through the helper array
	// copying the smaller element from the two halves into the original array
	while (helperLeft <= middle && helperRight <= high)
	{
		if (phelper[helperLeft] <= phelper[helperRight] )
		{
			array[current] = phelper[helperLeft];
			helperLeft++;
		}
		else
		{
			array[current] = phelper[helperRight];
			helperRight++;
		}
		current++;
	}

	// copy the rest of the left side of the array into the target array
	int remaining = middle - helperLeft;
	for (int i = 0; i <= remaining; i++)
	{
		array[current + i] = phelper[helperLeft + i];
	}
	printArray(array, size);
}

void mergesort(int array[], int* phelper, int low, int high, int size )
{
	if (low < high)
	{
		int middle = low + (high - low) / 2;
		mergesort(array, phelper, low, middle, size);
		mergesort(array, phelper, middle + 1, high, size);
		merge(array, phelper, low, middle, high, size);
		
	}
}

// main function
void mergesort(int array[], int size)
{
	if (size < 2) return;
	int* phelper = new int[size];
	mergesort(array, phelper, 0, size - 1, size);
	delete[] phelper;
}