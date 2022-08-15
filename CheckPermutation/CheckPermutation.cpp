// CheckPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// assuption is that we operate with ASCII encoding
//
// TimeC = O(n)
// SpaceC = O(1)
//
bool IsPermutation(const char* strIn, const char* strBase)
{
	if (nullptr == strIn || nullptr == strBase) return false;
	if (0 == strlen(strIn) || 0 == strlen(strBase)) return false;
	if (strlen(strIn) != strlen(strBase)) return false;

	int aLetters[128] = { 0 };

	for (int i = 0; i < strlen(strIn); i++)
	{
		char val = strIn[i];
		aLetters[val]++;
	}

	for (int i = 0; i < strlen(strBase); i++)
	{
		char val = strBase[i];
		aLetters[val]--;
		if (aLetters[val] < 0) return false;
	}

	return true;
}


void TestIsPerm()
{
	_ASSERT(false == IsPermutation(nullptr, nullptr));
	_ASSERT(false == IsPermutation("", ""));
	_ASSERT(false == IsPermutation("abc", "abcd"));

	_ASSERT(true == IsPermutation("abciop", "iopcba"));
	_ASSERT(false == IsPermutation("abciop", "iopcbs"));
}

int main()
{
	TestIsPerm();
    //std::cout << "Hello World!\n";
}
