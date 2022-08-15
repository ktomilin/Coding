#include "pch.h"
#include "..\..\Shared\Stack.h"

TEST(TestCtr, StackTest)
{
	Stack<int> stack;
	EXPECT_TRUE(stack.isEmpty());
}

TEST(TestPeek, StackTest)
{
	Stack<int> stack;
	
	stack.push(1);
	stack.push(2);
	stack.push(3);
	EXPECT_EQ( 3, stack.peek());
}

TEST(TestPop, StackTest)
{
	Stack<int> stack;

	stack.push(1);
	stack.push(3);
	stack.push(5);
	EXPECT_EQ(5, stack.pop());
	EXPECT_EQ(3, stack.pop());
}