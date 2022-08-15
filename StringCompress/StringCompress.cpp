// StringCompress.cpp : This file contains the 'main' function. Program execution begins and ends there.


// compress the string aabb -> a2b2.
// if output is => input, return input.
// assume 'A-z' range.

#include <iostream>

int countCompressedLength(const char* strIn)
{
	if (nullptr == strIn || 0 == strlen(strIn) ) return 0;
	int charCount{ 0 };
	size_t compressedLenght{ 0 };
	char buffer[33] = { 0 };
	for (size_t i = 0; i < strlen(strIn); i++)
	{
		charCount++;
		if ( i+1 >= strlen(strIn) || strIn[i] != strIn[i + 1])
		{
			compressedLenght += 1 + strlen(_itoa(charCount, buffer, 10));
			charCount = 0;
		}
	}

	if (compressedLenght >= strlen(strIn)) return 0;

	return compressedLenght;
}

bool compressString(const char* strIn, char*& strOut)
{
	int outLength = countCompressedLength(strIn);
	if (0 == outLength) return false;

	strOut = new char(outLength);
	strOut[0] = '\0';

	int charCount{ 0 };
	char buffer[33] = { 0 };

	// todo: fix the loop
	for (size_t i = 1; i < strlen(strIn); i++)
	{
		charCount++;
		if (strIn[i] != strIn[i - 1])
		{
			strncat_s(strOut, outLength, strIn + (i - 1), 1);
			strcat(strOut, _itoa(charCount, buffer, 10));
			charCount = 0;
		}
	}

	if (charCount > 0)
	{
		strncat_s(strOut, outLength, strIn+strlen(strIn)-1, 1);
		strcat(strOut, _itoa(charCount+1, buffer, 10));
	}

	return true;
}

void TestCompress()
{
	const char* cmpStr = "a3b3c4";
	char* resStr{ nullptr };
	bool res = compressString("aaabbbcccc", resStr);
	_ASSERT(res);
	_ASSERT(0 == strcmp(resStr, cmpStr));
	delete resStr;
}

void TestCompress1()
{
	const char* cmpStr = "abc";
	char* resStr{ nullptr };
	bool res = compressString("abc", resStr);

}

int main()
{
	TestCompress1();
}

