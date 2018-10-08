#pragma once

class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int firstValue);

	~BinaryTree();

	int CountLeaves();

	bool IsHeap();

	void AddTreeNode(int value);
private:
	struct BinaryTreeNode
	{
		int data;
		BinaryTreeNode * left;
		BinaryTreeNode * right;

		~BinaryTreeNode()
		{
			delete left;
			delete right;
		}
	};

	typedef BinaryTreeNode * TreePtr;
	TreePtr _root;

	int PrivateCountLeaves(TreePtr rootPtr);
	bool PrivateIsHeap(TreePtr rootPtr);
	TreePtr PrivateAddTreeNode(int value, TreePtr & rootPtr);
};