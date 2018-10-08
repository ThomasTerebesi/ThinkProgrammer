// "Problem: Find the Number of Leaves in a Binary Tree", page 163

#include <iostream>

class BinaryTree
{
public:
	BinaryTree();

	~BinaryTree();

	int CountLeaves();
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
};

int main()
{
	BinaryTree tree;

	std::cout << tree.CountLeaves() << std::endl;

	std::cin.get();

	return 0;
}

BinaryTree::BinaryTree()
{
	_root = new BinaryTreeNode;
	_root->data = 42;
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

