// StingPermutationsNoDups.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getPermutations(string str)
{
	vector<string> permutations;
	if (0 == str.length())
	{
		permutations.push_back("");
		return permutations;
	}

	char first = str[0];
	string reminder = str.substr(1);
	vector<string> words = getPermutations(reminder);
	for (string word : words)
	{
		int l = word.length();
		for (int j = 0; j <= l; j++)
		{ 
			string s = word;
			s.insert(j, 1, first);
			permutations.push_back(s);
		}
	}

	return permutations;
}

void testPerms()
{
	vector<string> words  = getPermutations("kons");
	for (string word : words) std::cout << word << endl; 
	std::cout << "permutations size:" << words.size();
}

int main()
{
	testPerms();
}

