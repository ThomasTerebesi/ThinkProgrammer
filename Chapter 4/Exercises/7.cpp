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
void Concatenate(string & str1, const string & str2);

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

	charNode * five = new charNode;
	charNode * six = new charNode;
	charNode * seven = new charNode;

	five->c = 'e';
	six->c = 'r';
	seven->c = 's';

	string strOne = one;
	strOne->next = two;
	two->next = three;
	three->next = four;
	four->next = nullptr;

	string strTwo = five;
	strTwo->next = six;
	six->next = seven;
	seven->next = nullptr;

	std::cout << "strOne before Concatenate(strOne, strTwo):" << std::endl;
	Output(strOne);

	Concatenate(strOne, strTwo);

	std::cout << "\nstrOne after Concatenate(strOne, strTwo):" << std::endl;
	Output(strOne);

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

void Concatenate(string & str1, const string & str2)
{
	// find the end of first string
	charNode * loopPtr = str1;

	while (loopPtr->next != nullptr)
		loopPtr = loopPtr->next;

	charNode * strEnd = loopPtr;

	// copy second string to end of first string
	loopPtr = str2;
	charNode * previousPtr = nullptr;
	charNode * strBegin = nullptr;
	
	while (loopPtr != nullptr)
	{
		charNode * newNode = new charNode;
		newNode->c = loopPtr->c;

		if (previousPtr == nullptr)
			strBegin = newNode;
		else
			previousPtr->next = newNode;

		previousPtr = newNode;
		loopPtr = loopPtr->next;
	}

	previousPtr->next = nullptr;

	// bring the two strings together
	strEnd->next = strBegin;
}
