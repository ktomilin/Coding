// MagicIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Magic index is defined as A[i] == i.
// Find a magic index in an array of sorted distinct values
//

#include <iostream>


int _magicIndex(int a[], int start, int end)
{
	if (end < start) return -1;
	int half = (end + start) / 2;
	if (a[half] == half) return half;

	if (a[half] > half) return _magicIndex(a, start, half);
	else return _magicIndex(a, half + 1, end);

	return -1;
}

int magicIndex(int a[], int size)
{
	if ( size <= 0 ) return -1;
	return _magicIndex(a, 0, size-1);
}

void testMagicIndex()
{
	int a[] = { -5, -2, 0, 3, 5, 6,20, 50, 80 };
	_ASSERTE(3 == magicIndex(a, _countof(a)) );
}

int main()
{
	testMagicIndex();
    //std::cout << "Hello World!\n";
}

