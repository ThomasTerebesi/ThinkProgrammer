#include <iostream>

const int STRING_SIZE = 13;

void PrintReverse(char charArray[], int size);

int main()
{
	char helloWorld[STRING_SIZE] = "Hello World!";

	std::cout << helloWorld << std::endl;

	PrintReverse(helloWorld, STRING_SIZE);

	std::cout << std::endl;

	std::cin.get();

	return 0;
}

void PrintReverse(char charArray[], int size)
{
	if (size == 0)
		return;

	std::cout << charArray[size - 1];
	PrintReverse(charArray, size - 1);
}
