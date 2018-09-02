#include <iostream>

const int ARRAY_SIZE = 10;

int main()
{

	int intArray[ARRAY_SIZE] = { 87, 28, 100, 78, 84, 75, 70, 81, 68 };

	std::cout << "Contents of intArray before insertion sort:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << intArray[i] << "\t";

	// insertion sort
	int start = 0;
	int end = ARRAY_SIZE - 1;
	for (int i = start + 1; i <= end; i++)
	{
		for (int j = i; j > start && intArray[j - 1] > intArray[j]; j--)
		{
			int temp = intArray[j - 1];
			intArray[j - 1] = intArray[j];
			intArray[j] = temp;
		}
	}

	std::cout << "\n\nContents of intArray after insertion sort:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << intArray[i] << "\t";

	std::cout << "\n" << std::endl;

	std::cin.get();

	return 0;
}