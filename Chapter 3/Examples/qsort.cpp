#include <iostream>
#include <cstdlib>

const int ARRAY_SIZE = 10;

int compareFunc(const void* voidA, const void* voidB)
{
	int * intA = (int *)(voidA);
	int * intB = (int *)(voidB);
	return *intA - *intB;
}

int main()
{
	int intArray[ARRAY_SIZE] = { 87, 28, 100, 78, 84, 75, 70, 81, 68 };
	
	std::cout << "Contents of intArray before qsort():" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << intArray[i] << "\t";

	// qsort()
	qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);

	std::cout << "\n\nContents of intArray after qsort():" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << intArray[i] << "\t";

	std::cout << "\n" << std::endl;

	std::cin.get();

	return 0;
}