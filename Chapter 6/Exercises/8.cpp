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

ListPtr Copy(ListPtr head);

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

	std::cout << "Hello Linked List!" << std::endl;

	std::cin.get();

	return 0;
}

ListPtr Copy(ListPtr head)
{
	if (head == nullptr)
		return nullptr;

	
}
