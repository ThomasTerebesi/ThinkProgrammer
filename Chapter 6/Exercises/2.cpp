#include <iostream>

const int ARRAY_SIZE = 8;

bool HasOddParityIterative(int binaryArray[], int size);
bool HasOddParityRecursive(int binaryArray[], int size);

int main()
{
	int binaryArrayOne[ARRAY_SIZE] = { 1, 0, 1, 0, 1, 0, 0, 1 };	// false
	int binaryArrayTwo[ARRAY_SIZE] = { 1, 0, 1, 1, 0, 1, 1, 0 };	// true


	std::cout << "HasOddParityIterative(binaryArrayOne, ARRAY_SIZE):" << std::endl;
	std::cout << HasOddParityIterative(binaryArrayOne, ARRAY_SIZE) << std::endl;

	std::cout << "\nHasOddParityRecursive(binaryArrayOne, ARRAY_SIZE):" << std::endl;
	std::cout << HasOddParityRecursive(binaryArrayOne, ARRAY_SIZE) << std::endl;


	std::cout << "\n\nHasOddParityIterative(binaryArrayTwo, ARRAY_SIZE):" << std::endl;
	std::cout << HasOddParityIterative(binaryArrayTwo, ARRAY_SIZE) << std::endl;

	std::cout << "\nHasOddParityRecursive(binaryArrayTwo, ARRAY_SIZE):" << std::endl;
	std::cout << HasOddParityRecursive(binaryArrayTwo, ARRAY_SIZE) << std::endl;

	std::cin.get();

	return 0;
}

bool HasOddParityIterative(int binaryArray[], int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
		if (binaryArray[i] == 1)
			count++;

	if (count % 2 != 0)
		return true;
	else
		return false;
}

bool HasOddParityRecursive(int binaryArray[], int size)
{
	if (size == 0)
		return false;

	return (binaryArray[size - 1] == 0 + HasOddParityRecursive(binaryArray, size - 1));
}
