#include "pch.h"
#include "..\..\Shared\BinTree.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

/*
template<class T> TreeNode<T>* CreateBST()
{
//			8
//		4		10
//	2		6		20
	
	
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

	return node8;
}
*/

TEST(TestDeleteTree, BinTreeTest) {

	TreeNode<int>* root = CreateBST<int>();
	DeleteTree<int>(root);
	EXPECT_EQ(nullptr, root);
	//EXPECT_TRUE(true);
}

TEST(TestInOrderTraversal, BinTreeTest) {

	TreeNode<int>* root = CreateBST<int>();
	std::cout << "InOrderTraversal" << endl;
	InOrderTraversal<int>(root);
	DeleteTree<int>(root);
	EXPECT_EQ(nullptr, root);
	//EXPECT_TRUE(true);
}

TEST(TestInOrderTraversalIterative, BinTreeTest) {

	TreeNode<int>* root = CreateBST<int>();
	std::cout << "InOrderTraversal Iterative" << endl;
	InOrderTraversalIterative<int>(root);
	DeleteTree<int>(root);
	EXPECT_EQ(nullptr, root);
	//EXPECT_TRUE(true);
}

TEST(TestPreOrderTraversal, BinTreeTest) {

	TreeNode<int>* root = CreateBST<int>();
	std::cout << "PreOrderTraversal" << endl;
	PreOrderTraversal<int>(root);
	DeleteTree<int>(root);
	EXPECT_EQ(nullptr, root);
	//EXPECT_TRUE(true);
}



TEST(TestPostOrderTraversal, BinTreeTest) {

	TreeNode<int>* root = CreateBST<int>();
	std::cout << "PostOrderTraversal" << endl;
	PostOrderTraversal<int>(root);
	DeleteTree<int>(root);
	EXPECT_EQ(nullptr, root);
}

TEST(TestPostOrderTraversalIterative, BinTreeTest) {

	TreeNode<int>* root = CreateBST<int>();
	std::cout << "PostOrderTraversal Iterative" << endl;
	PostOrderTraversalIterative<int>(root);
	DeleteTree<int>(root);
	EXPECT_EQ(nullptr, root);
}

TEST(TestsearchBFS, BinTreeTest) {

	TreeNode<int>* root = CreateBST<int>();
	std::cout << "BFS search" << endl;
	searchBFS<int>(root);
	DeleteTree<int>(root);
	EXPECT_EQ(nullptr, root);
}