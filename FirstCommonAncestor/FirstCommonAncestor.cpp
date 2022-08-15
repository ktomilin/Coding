// FirstCommonAncestor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\..\Shared\BinTree.h"


TreeNode<int>* firstCommonAncestor(TreeNode<int>* root, TreeNode<int>* first, TreeNode<int>* second, bool& found)
{

	if (nullptr == root) return root;
	if (first == root) return first;
	if (second == root) return second;

	TreeNode<int>* left = firstCommonAncestor(root->left, first, second, found);
	if (found) return left;
	TreeNode<int>* right = firstCommonAncestor(root->right, first, second, found);
	if (found) return right;

	if ((first == left && second == right) || (second == left && first == right))
	{
		found = true;
		return root;
	}
	else if (first == left || first == right) return first;
	else if (second == left || second == right) return second;
	else return nullptr;
}

template<class T> TreeNode<T>* CreateBSTSpecial(TreeNode<T>*& parent, TreeNode<T>*& first, TreeNode<T>*& second)
{
	//				8
	//		4			10
	//	2		6			20
	//				7


	TreeNode<T>* node8 = new TreeNode<T>(8);
	TreeNode<T>* node4 = new TreeNode<T>(4);
	TreeNode<T>* node2 = new TreeNode<T>(2);
	TreeNode<T>* node6 = new TreeNode<T>(6);
	TreeNode<T>* node7 = new TreeNode<T>(7);

	node4->left = node2;
	node4->right = node6;
	node8->left = node4;
	node6->right = node7;

	TreeNode<T>* node10 = new TreeNode<T>(10);
	TreeNode<T>* node20 = new TreeNode<T>(20);

	node10->right = node20;
	node8->right = node10;

	first = node20;
	second = node7;
	parent = node8;

	return node8;
}

void Test()
{
	TreeNode<int>* first;
	TreeNode<int>* second;
	TreeNode<int>* real_parent;
	TreeNode<int>* root = CreateBSTSpecial<int>(real_parent, first, second);

	bool found = false;
	TreeNode<int>* parent = firstCommonAncestor(root, first, second, found);
	_ASSERTE(real_parent == parent);
	_ASSERTE(found);
	DeleteTree(root);
}

int main()
{
	Test();
}

