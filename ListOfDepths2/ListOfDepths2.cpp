// ListOfDepths2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include "..\..\Shared\BinTree.h"
using namespace std;

template<class T> vector< list<TreeNode<T>*>*> ListsOfDepth(TreeNode<T>* root)
{
	vector< list<TreeNode<T>*>*> outLists;
	if (nullptr == root) return outLists;

	list<TreeNode<T>*>* current_list = new list<TreeNode<T>*>();
	current_list->push_back(root);

	while (current_list->size() > 0)
	{
		outLists.push_back(current_list);
		list<TreeNode<T>*>* parent_list = current_list;
		current_list = new list<TreeNode<T>*>();
		for (TreeNode<T>* node : *parent_list)
		{
			VisitNode(node);
			if (node->left)	current_list->push_back(node->left);
			if (node->right) current_list->push_back(node->right);
		}
	}

	return outLists;
}

template<class T> TreeNode<T>* CreateBST()
{
	//			8
	//		4		10
	//	2		6		20
	//1						27


	TreeNode<T>* node8 = new TreeNode<T>(8);
	TreeNode<T>* node4 = new TreeNode<T>(4);
	TreeNode<T>* node2 = new TreeNode<T>(2);
	TreeNode<T>* node6 = new TreeNode<T>(6);

	node4->left = node2;
	node4->right = node6;
	node8->left = node4;

	TreeNode<T>* node10 = new TreeNode<T>(10);
	TreeNode<T>* node20 = new TreeNode<T>(20);

	node10->right = node20;
	node8->right = node10;

	TreeNode<T>* node1 = new TreeNode<T>(1);
	node2->left = node1;

	TreeNode<T>* node27 = new TreeNode<T>(27);
	node20->right = node27;

	return node8;
}

template<class T> void PrintNodesList(list<TreeNode<T>*>* list)
{
	for(TreeNode<T> * node : *list)
	{
		std::cout << node->data << " ";
	}
}

void testListsOfDepth()
{
	TreeNode<int>* root = CreateBST<int>();
	vector< list<TreeNode<int>*>*> levelLists = ListsOfDepth<int>(root);
	int size = levelLists.size();
	std::cout << "Nember of levels: " << size << endl;
	for (list<TreeNode<int>*>* list : levelLists)
	{
		PrintNodesList<int>(list);
		std::cout << endl << "------" << endl;
		delete list;
	}
}

//void testListsOfDepth()
//{
//	std::list<TreeNode<int>*>* list = new std::list<TreeNode<int>*>();
//	TreeNode<int>* node8 = new TreeNode<int>(8);
//	TreeNode<int>* node4 = new TreeNode<int>(4);
//
//	list->push_back(node8);
//	list->push_back(node4);
//
//	for (TreeNode<int>* node : *list)
//	{
//		std::cout << node->data << " ";
//	}
//}

int main()
{
	testListsOfDepth();
	//std::cout << "Hello World!\n";
}