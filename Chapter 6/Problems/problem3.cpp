// "Problem: Find the Largest Value in a Binary Tree"

#include <iostream>

struct TreeNode
{
	int data;
	TreeNode * left = nullptr;
	TreeNode * right = nullptr;
};

typedef TreeNode * TreePtr;

int MaxValue(TreePtr root)
{
	if (root == nullptr)
		return 0;

	if (root->right == nullptr && root->left == nullptr)
		return root->data;

	int leftMax = MaxValue(root->left);
	int rightMax = MaxValue(root->right);

	int maxNum = root->data;

	if (leftMax > maxNum)
		maxNum = leftMax;

	if (rightMax > maxNum)
		maxNum = rightMax;

	return maxNum;
}

int main()
{
	TreeNode n1;
	n1.data = 28;
	
	TreeNode n2;
	n2.data = 117;

	TreeNode n3;
	n3.data = 64;

	TreeNode n4;
	n4.data = 95;

	TreeNode n5;
	n5.data = 139;

	TreeNode n6;
	n6.data = 80;

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.right = &n6;

	TreePtr treeRoot = &n1;

	std::cout << MaxValue(treeRoot) << std::endl;

	std::cin.get();

	return 0;
}