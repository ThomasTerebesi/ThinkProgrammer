#include <iostream>

struct ListNode
{
	int data;
	ListNode * next;

	~ListNode()
	{
		delete next;
	}
};

typedef ListNode * ListPtr;

int OccurencesOfIterative(ListPtr head, int target);
int OccurencesOfRecursive(ListPtr head, int target);

int main()
{
	ListPtr head;

	ListNode * node1 = new ListNode;
	node1->data = 12;

	ListNode* node2 = new ListNode;
	node2->data = 87;

	ListNode* node3 = new ListNode;
	node3->data = -39;

	ListNode* node4 = new ListNode;
	node4->data = 12;

	ListNode* node5 = new ListNode;
	node5->data = 12;

	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = nullptr;

	std::cout << "OccurencesOfIterative(head, 12):" << std::endl;
	std::cout << OccurencesOfIterative(head, 12) << std::endl;

	std::cout << "\nOccurencesOfRecursive(head, 12):" << std::endl;
	std::cout << OccurencesOfRecursive(head, 12) << std::endl;

	std::cin.get();

	return 0;
}

int OccurencesOfIterative(ListPtr head, int target)
{
	ListPtr loopPtr = head;
	int count = 0;

	while (loopPtr != nullptr)
	{
		if (loopPtr->data == target)
			count++;

		loopPtr = loopPtr->next;
	}

	return count;
}

int OccurencesOfRecursive(ListPtr head, int target)
{
	if (head == nullptr)
		return 0;

	return ((head->data == target) + OccurencesOfRecursive(head->next, target));
}
