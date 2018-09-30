// "Problem: Counting Negative Numbers in a Singly Linked List", page 159

#include <iostream>

struct ListNode
{
	int data;
	ListNode * next;
};

typedef ListNode * ListPtr;

int CountNegative(ListPtr head)
{
	if (head == nullptr)
		return 0;

	int listCount = CountNegative(head->next);

	if (head->data < 0)
		listCount++;

	return listCount;
}

int main()
{
	ListNode n1;
	n1.data = 2;

	ListNode n2;
	n2.data = 11;

	ListNode n3;
	n3.data = -83;

	ListNode n4;
	n4.data = -4;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = nullptr;

	ListPtr listHead = &n1;

	std::cout << CountNegative(listHead) << std::endl;

	std::cin.get();

	

	return 0;
}