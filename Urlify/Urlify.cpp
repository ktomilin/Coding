// Urlify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Assumption we use ASCII.
//  TimeC = O(n)
//  SpaceC = O(1)
//
void Urlify(char str[], int size)
{
	if (size < 3) return;

	int index = size - 1;
	char space = ' ';
	int i = index;

	while (str[i] == space) i--;
	for (; i >= 0; i--)
	{
		if (str[i] == space)
		{
			str[index--] = '0';
			str[index--] = '2';
			str[index--] = '%';
		}
		else
		{
			str[index--] = str[i];
		}
	}
}

void TestUrlify()
{
	char a1[] = "a";
	int size1 = 1;
	char aa1[] = "a";
	Urlify(a1, size1);
	_ASSERT(0 == strcmp(a1, aa1));

	char a2[] = "s  p    ";
	int size2 = 8;
	char aa2[] = "s%20%20p";
	Urlify(a2, size2);
	_ASSERT(0 == strcmp(a2, aa2));
}

int main()
{
	TestUrlify();
    std::cout << "All done!\n";
}

