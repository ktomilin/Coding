// MinimalTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\..\Shared\BinTree.h"
#include <vector>

using namespace std;

TreeNode<int>* _buildMinTree(const vector<int>& nums, int start, int end)
{
	if (end < start) return nullptr;

	int mid = (start + end) / 2;
	TreeNode<int>* root = new TreeNode<int>(nums[mid]);
	root->left = _buildMinTree(nums, start, mid - 1);
	root->right = _buildMinTree(nums, mid + 1, end);

	return root;

}

TreeNode<int>* buildMinTree(const vector<int>& nums)
{
	return _buildMinTree(nums, 0, nums.size() - 1);
}

void testMinTree()
{
	vector<int> nums{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	TreeNode<int>* root = buildMinTree(nums);
	InOrderTraversal(root);
	DeleteTree<int>(root);
}

int main()
{
	testMinTree();
    //std::cout << "Hello World!\n";
}

