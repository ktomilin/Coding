// ListOfDepths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "..\..\Shared\LinkedList.h"
#include "..\..\Shared\BinTree.h"
using namespace std;

template < class T > struct TreeNodeEx
{
	TreeNodeEx<T>* left;
	TreeNodeEx<T>* right;
	T data;
	int level;

	TreeNodeEx(T item) : data(item), left(nullptr), right(nullptr), level(0) {};
};


template<class T> vector< LinkedList<TreeNodeEx<T>*>*> ListsOfDepth(TreeNodeEx<T>* root)
{
	vector< LinkedList<TreeNodeEx<T>*>*> outLists;
	if (nullptr == root) return outLists;

	LinkedList<TreeNodeEx<T>*> list;
	root->level = 0;
	list.push_back(root);

	

	LinkedList<TreeNodeEx<T>*>* level_list = new LinkedList<TreeNodeEx<T>*>();
	int list_level = root->level;

	while (list.size() > 0)
	{
		TreeNodeEx<T>*& currNode = list.front();
		VisitNode(currNode);
		
		if (list_level != currNode->level)
		{
			outLists.push_back(level_list);
			level_list = new LinkedList<TreeNodeEx<T>*>();
			list_level = currNode->level;
		}
		level_list->push_back(currNode);

		if (currNode->left)
		{
			(currNode->left)->level = currNode->level + 1;
			list.push_back(currNode->left);
		}
		if (currNode->right)
		{
			(currNode->right)->level = currNode->level+1;
			list.push_back(currNode->right);
		}
		list.pop_front();
	}
	outLists.push_back(level_list);
	return outLists;
}

template<class T> TreeNodeEx<T>* CreateBST()
{
	//			8
	//		4		10
	//	2		6		20
	//1						27


	TreeNodeEx<T>* node8 = new TreeNodeEx<T>(8);
	TreeNodeEx<T>* node4 = new TreeNodeEx<T>(4);
	TreeNodeEx<T>* node2 = new TreeNodeEx<T>(2);
	TreeNodeEx<T>* node6 = new TreeNodeEx<T>(6);

	node4->left = node2;
	node4->right = node6;
	node8->left = node4;

	TreeNodeEx<T>* node10 = new TreeNodeEx<T>(10);
	TreeNodeEx<T>* node20 = new TreeNodeEx<T>(20);

	node10->right = node20;
	node8->right = node10;

	TreeNodeEx<T>* node1 = new TreeNodeEx<T>(1);
	node2->left = node1;

	TreeNodeEx<T>* node27 = new TreeNodeEx<T>(27);
	node20->right = node27;

	return node8;
}

template<class T> void VisitNode(TreeNodeEx<T>* node)
{
	std::cout << "Node value: " << node->data << endl;
}

template<class T> void PrintNodesList(LinkedList<TreeNodeEx<T>*>* list)
{
	while ( list->size() > 0)
	{
		TreeNodeEx<T>* node = list->front();
		std::cout << node->data << " ";
		list->pop_front();
	}
}

void testListsOfDepth()
{
	TreeNodeEx<int>* root = CreateBST<int>();
	vector< LinkedList<TreeNodeEx<int>*>*> levelLists = ListsOfDepth<int>(root);
	int size = levelLists.size();
	std::cout << "Nember of levels: " << size << endl;
	for (LinkedList<TreeNodeEx<int>*>* list : levelLists)
	{
		PrintNodesList<int>( list );
		std::cout << endl << "------" << endl;
		delete list;
	}
}

int main()
{
	testListsOfDepth();
    //std::cout << "Hello World!\n";
}

