#include <iostream>

struct charNode
{
	char c;
	charNode * next;

	~charNode()
	{
		delete next;
	}
};

typedef charNode * string;

void Output(const string & str);
void Append(string & str, char c);
char CharacterAt(const string & str, int n);

int main()
{
	charNode * one = new charNode;
	charNode * two = new charNode;
	charNode * three = new charNode;
	charNode * four = new charNode;

	one->c = 't';
	two->c = 'e';
	three->c = 's';
	four->c = 't';

	string str = one;
	str->next = two;
	two->next = three;
	three->next = four;
	four->next = nullptr;

	Output(str);

	Append(str, '!');

	Output(str);

	std::cout << CharacterAt(str, 2) << std::endl;

	std::cin.get();

	return 0;
}

void Output(const string & str)
{
	charNode * loopPtr = str;

	while (loopPtr != nullptr)
	{
		std::cout << loopPtr->c;
		loopPtr = loopPtr->next;
	}

	std::cout << std::endl;
}

void Append(string & str, char c)
{
	charNode * newNode = new charNode;
	newNode->c = c;
	newNode->next = nullptr;

	charNode * loopPtr = str;

	while (loopPtr->next != nullptr)
		loopPtr = loopPtr->next;

	loopPtr->next = newNode;
}

char CharacterAt(const string & str, int n)
{
	int counter = 0;
	charNode * loopPtr = str;

	while (counter < n)
	{
		loopPtr = loopPtr->next;
		counter++;
	}

	return loopPtr->c;
}
