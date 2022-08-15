// ThreeInOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class FixedStack
{
	static const int numOfStacks = 3;
	int capacity;
	vector<int> values;
	int sizes[numOfStacks];

public:

	FixedStack(int stackSize) : capacity(stackSize)
	{
		values.resize(numOfStacks * stackSize);
		for ( int i=0; i< numOfStacks; ++i ) sizes[i] = 0;
	}

	int indexOfTop(int stackNum)
	{
		int offset = (stackNum-1) * capacity;
		offset += sizes[stackNum-1];

		return offset;
	}

	bool isFull(int stackNum) const {
		return sizes[stackNum-1] == capacity;
	}

	bool isEmpty(int stackNum) const {
		return 0 == sizes[stackNum-1];
	}

	void push(int stackNum, int value)
	{
		// validate stackNum
		if (isFull(stackNum)) throw std::out_of_range("stack is full");
		values[indexOfTop(stackNum)] = value;
		sizes[stackNum-1]++;
	}

	int pop(int stackNum)
	{
		// validate stackNum
		if (isEmpty(stackNum)) throw std::out_of_range("stack is empty");
		int val = values[indexOfTop(stackNum)-1];
		values[indexOfTop(stackNum)-1] = 0;
		sizes[stackNum-1]--;
		return val;
	}

};


void testTripleStack()
{
	FixedStack stack3(10);
	stack3.push(1, 1);
	stack3.push(1, 11);
	stack3.push(1, 111);

	stack3.push(2, 2);
	stack3.push(2, 22);
	stack3.push(2, 222);

	stack3.push(3, 3);

	_ASSERTE(111 == stack3.pop(1));
	_ASSERTE(222 == stack3.pop(2));
	_ASSERTE(3 == stack3.pop(3));

}

int main()
{
	testTripleStack();
    //std::cout << "Hello World!\n";
}

