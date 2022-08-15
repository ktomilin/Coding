// LoopDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "..\..\Shared\LinkedList.h"


struct Node
{
	Node* next;
	int val;
};


Node* detectLoop(Node* head)
{
	if (nullptr == head) return head;

	Node* slow = head;
	Node* fast = head;

	// find meting point: LOOP_SIZE - k steps into the linked list
	while (fast != nullptr && slow != nullptr )
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}
	if (fast == nullptr || slow == nullptr) return nullptr;

	// move slow to start, keep fast at meeting point.
	// they are both k steps away from the loop start
	slow = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}


void createLoopesList(Node*& head, Node*& loopStart)
{
	Node* tmp = new(std::nothrow)  Node();
	tmp->val = 1;
	tmp->next = 
	return nullptr;
}

void testListPartition()
{
	// lambda
	createLoopesList();
}

int main()
{
    std::cout << "Hello World!\n";
}

