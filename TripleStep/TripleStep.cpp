// TripleStep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int tripleStep(const int& numSteps)
{
	if (numSteps < 0) return 0;
	if (0 == numSteps) return 1;

	return tripleStep(numSteps - 1) + tripleStep(numSteps - 2) + tripleStep(numSteps - 3);
}

void testTripleStep()
{
	int ways = tripleStep(3);
	_ASSERTE(4 == ways);

	ways = tripleStep(4);
	_ASSERTE(7 == ways);

	ways = tripleStep(10);
	_ASSERTE(274 == ways);

}

int main()
{
	testTripleStep();
    //std::cout << "Hello World!\n";
}

