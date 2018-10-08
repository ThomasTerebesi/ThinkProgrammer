#include "binaryTree.h"

BinaryTree::BinaryTree()
{
	_root = new BinaryTreeNode;
	_root->data = 0;
	_root->left = nullptr;
	_root->right = nullptr;
}

BinaryTree::BinaryTree(int firstValue)
{
	_root = new BinaryTreeNode;
	_root->data = firstValue;
	_root->left = nullptr;
	_root->right = nullptr;
}

BinaryTree::~BinaryTree()
{
	delete _root;
}

int BinaryTree::CountLeaves()
{
	return PrivateCountLeaves(_root);
}

bool BinaryTree::IsHeap()
{
	return PrivateIsHeap(_root);
}

void BinaryTree::AddTreeNode(int value)
{
	PrivateAddTreeNode(value, _root);
}

int BinaryTree::PrivateCountLeaves(TreePtr rootPtr)
{
	if (rootPtr == nullptr)
		return 0;

	if (rootPtr->left == nullptr && rootPtr->right == nullptr)
		return 1;

	int leftCount = PrivateCountLeaves(rootPtr->left);
	int rightCount = PrivateCountLeaves(rootPtr->right);

	return leftCount + rightCount;
}

bool BinaryTree::PrivateIsHeap(TreePtr rootPtr)
{
	// TODO: Check if binary tree is a heap. :)

	return true;
}

BinaryTree::TreePtr BinaryTree::PrivateAddTreeNode(int value, TreePtr & rootPtr)
{
	if (rootPtr == nullptr)
	{
		rootPtr = new BinaryTreeNode;
		rootPtr->data = value;
		rootPtr->left = nullptr;
		rootPtr->right = nullptr;

		return rootPtr;
	}
	else if (rootPtr->left == nullptr)
		rootPtr->left = PrivateAddTreeNode(value, rootPtr->left);
	else if (rootPtr->right == nullptr)
		rootPtr->right = PrivateAddTreeNode(value, rootPtr->right);
}