// PowerSets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

using vecVec = vector<vector<int>>;


vecVec powerSets(const vector<int>& set, int index)
{
	vecVec allSubSets;
	if (index == set.size())
	{
		allSubSets.emplace_back(vector<int>()); // empty set
	}
	else
	{
		allSubSets = powerSets(set, index + 1);
		int item = set[index];
		vecVec moreSets;
		for (vector<int> subset : allSubSets)
		{
			vector<int> newset(subset);
			newset.emplace_back(item);
			moreSets.emplace_back(newset);
		}

		for (vector<int> subset : moreSets) allSubSets.emplace_back(subset);
	}

	return allSubSets;
}



void testSubsets()
{
	vector<int> set{ 1, 2, 3 };
	vecVec resVec = powerSets(set, 0);
	_ASSERTE(8 == resVec.size());
	for (vector<int> subset : resVec)
	{
		std::cout << "Subset\n";
		for (auto i : subset) std::cout << i << " ";
		std::cout << "\n";
	}


}

int main()
{
	testSubsets();
//    std::cout << "Hello World!\n";
}

