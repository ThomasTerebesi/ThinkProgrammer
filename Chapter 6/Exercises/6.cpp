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

bool HasOddParityIterative(ListPtr head);
bool HasOddParityRecursive(ListPtr head);

int main()
{
	ListPtr head;

	ListNode * node1 = new ListNode;
	node1->data = 1;

	ListNode* node2 = new ListNode;
	node2->data = 0;

	ListNode* node3 = new ListNode;
	node3->data = 1;

	ListNode* node4 = new ListNode;
	node4->data = 1;

	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;

	std::cout << "HasOddParityIterative(head):" << std::endl;
	std::cout << HasOddParityIterative(head) << std::endl;

	std::cout << "\nHasOddParityRecursive(head):" << std::endl;
	std::cout << HasOddParityRecursive(head) << std::endl;


	std::cin.get();

	return 0;
}

bool HasOddParityIterative(ListPtr head)
{
	ListPtr loopPtr = head;

	int count = 0;

	while (loopPtr != nullptr)
	{
		if (loopPtr->data == 1)
			count++;

		loopPtr = loopPtr->next;
	}

	return (count % 2 != 0);
}

bool HasOddParityRecursive(ListPtr head)
{
	if (head == nullptr)
		return false;

	return (head->data == 0 + HasOddParityRecursive(head->next));
}
