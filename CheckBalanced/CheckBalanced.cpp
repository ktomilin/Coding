// CheckBalanced.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\..\Shared\BinTree.h"
#include <vector>
#include <algorithm>

using namespace std;

bool isBalanced(TreeNode<int>* root, int& height)
{
	if (nullptr == root)
	{
		height = 0;
		return true;
	}

	int lHeight{ 0 };
	int rHeight{ 0 };
	bool isLeftBalanced = isBalanced(root->left, lHeight);
	bool isRightBalanced = isBalanced(root->right, rHeight);

	height += max(lHeight, rHeight) +1;

	return isLeftBalanced && isRightBalanced && (lHeight - rHeight) <= 1;
}


template<class T> TreeNode<T>* CreateInbalancedBST()
{
	//			8
	//		4		10
	//	2		6		20
//			3
//		1

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
	TreeNode<T>* node3 = new TreeNode<T>(3);

	node6->left = node3;
	node3->left = node1;

	return node8;
}

void testIsBalanced()
{
	TreeNode<int>* root = CreateBST<int>();
	int height{ 0 };
	_ASSERTE(isBalanced(root, height));
	_ASSERTE(3 == height);
	DeleteTree<int>(root);

	TreeNode<int>* root1 = CreateInbalancedBST<int>();
	height = 0 ;
	_ASSERTE(false == isBalanced(root1, height));
	//_ASSERTE(3 == height);
	DeleteTree<int>(root);

}

int main()
{
	testIsBalanced();
	//std::cout << "Hello World!\n";
}
