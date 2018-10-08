#include <iostream>
#include "binaryTree.h"


int main()
{
	BinaryTree tree(23);

	tree.AddTreeNode(12);
	tree.AddTreeNode(53);
	tree.AddTreeNode(2);
	tree.AddTreeNode(84);
	tree.AddTreeNode(69);

	std::cout << tree.CountLeaves() << std::endl;

	std::cin.get();

	return 0;
}


