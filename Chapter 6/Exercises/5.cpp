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

int SumOfPositiveIterative(ListPtr head);
int SumOfPositiveRecursive(ListPtr head);

int main()
{
	ListPtr head;

	ListNode * node1 = new ListNode;
	node1->data = 12;

	ListNode* node2 = new ListNode;
	node2->data = 87;

	ListNode* node3 = new ListNode;
	node3->data = -39;

	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = nullptr;

	std::cout << "SumOfPositiveIterative(head):" << std::endl;
	std::cout << SumOfPositiveIterative(head) << std::endl;

	std::cout << "\nSumOfPositiveRecursive(head):" << std::endl;
	std::cout << SumOfPositiveRecursive(head) << std::endl;


	std::cin.get();

	return 0;
}

int SumOfPositiveIterative(ListPtr head)
{
	ListPtr loopPtr = head;
	int sum = 0;

	while (loopPtr != nullptr)
	{
		if (loopPtr->data > 0)
			sum += loopPtr->data;

		loopPtr = loopPtr->next;
	}

	return sum;
}

int SumOfPositiveRecursive(ListPtr head)
{
	if (head == nullptr)
		return 0;

	int lastNumber = head->data > 0 ? head->data : 0;
	int allButLastSum = SumOfPositiveRecursive(head->next);

	return lastNumber + allButLastSum;
}