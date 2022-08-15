// Partition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// write code to partition linked list around value x, such that all nodes less than x come before all nodes greater or equal than x
// Partition element x can appear anywhere in the right partition:
//
// Input: 3->5->8->5->10->2->1  [ partition 5 ]
// Out: 3->2->1 -> 10->5->5->8

#include <iostream>
#include "LinkedList.h"
#include <vector>
using namespace std;

template < class T > class LinkedListWithPartition : public LinkedList<T>
{
public:

	LinkedListWithPartition() :LinkedList<T>() {};
	~LinkedListWithPartition() {};

	using LinkedList<T>::length;
	using LinkedList<T>::head;
	using LinkedList<T>::tail;

	void partition(const T& partVal)
	{
		if (!head) return;
		bool bHitPartition{ false };
		Node<T>* curr = head;
		Node<T>* prev{ nullptr };

		while (curr)
		{
			if (curr->data < partVal && bHitPartition)
			{
				// move to head
				prev->next = curr->next;
				if (nullptr == prev->next) tail = prev;
				curr->next = head;
				head = curr;
				curr = prev->next;
			}
			else if (curr->data < partVal && !bHitPartition)
			{
				curr = curr->next;
			}
			else if (curr->data >= partVal)
			{
				prev = curr;
				curr = curr->next;
				bHitPartition = true;
			}
		}
	}
};


void testListPartition()
{
	// lambda
	auto createList = [](vector<int> vec, LinkedListWithPartition<int>& list )
	{
		for (auto i : vec) list.push_back(i);
		list.print_list();
	};

	//vector<int> vec{ 3, 5, 8, 5, 10, 2, 1 };
	//vector<int> vec{ 1, 2, 3, 5 };
	vector<int> vec{ 21, 15, 1, 45, 2, 104, 4 , 500, 10, 2, 1 };
	LinkedListWithPartition<int> list;
	createList(vec, list);

	list.partition(40);
	list.print_list();
}

int main()
{
	testListPartition();
}

