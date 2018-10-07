// "Problem: Display a Linked List in Order" and "Problem: Display a Linked List in Reverse Order", page 168

#include <iostream>
#include <stack>

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

void DisplayListForwardsRecursion(ListPtr head);
void DisplayListBackwardsRecursion(ListPtr head);
void DisplayListForwardsIterative(ListPtr head);
void DisplayListBackwardsIterative(ListPtr head);

int main()
{
	ListPtr head;

	ListNode * node1 = new ListNode;
	node1->data = 12;

	ListNode* node2 = new ListNode;
	node2->data = 87;

	ListNode* node3 = new ListNode;
	node3->data = 39;

	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = nullptr;

	std::cout << "DisplayListForwardsRecursion(head):" << std::endl;
	DisplayListForwardsRecursion(head);
	std::cout << "\nDisplayListForwardsIterative(head):" << std::endl;
	DisplayListForwardsIterative(head);

	std::cout << "\n\nDisplayListBackwardsRecursion(head):" << std::endl;
	DisplayListBackwardsRecursion(head);
	std::cout << "\nDisplayListBackwardsIterative(head):" << std::endl;
	DisplayListBackwardsIterative(head);

	std::cout << std::endl;

	std::cin.get();

	return 0;
}

void DisplayListForwardsRecursion(ListPtr head)
{
	if (head != nullptr)
	{
		std::cout << head->data << "\t";
		DisplayListForwardsRecursion(head->next);
	}
}

void DisplayListBackwardsRecursion(ListPtr head)
{
	if (head != nullptr)
	{
		DisplayListBackwardsRecursion(head->next);
		std::cout << head->data << "\t";
	}
}

void DisplayListForwardsIterative(ListPtr head)
{
	for(ListPtr current = head; current != nullptr; current = current->next)
		std::cout << current->data << "\t";
}

void DisplayListBackwardsIterative(ListPtr head)
{
	std::stack<ListPtr> nodes;
	for(ListPtr current = head; current != nullptr; current = current->next)
		nodes.push(current);

	while(!nodes.empty())
	{
		ListPtr current = nodes.top();
		nodes.pop();
		std::cout << current->data << "\t";
	}
}