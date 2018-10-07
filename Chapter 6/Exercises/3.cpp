#include <iostream>

const int ARRAY_SIZE = 10;

int OccurencesOfIterative(int intArray[], int size, int target);
int OccurencesOfRecursive(int intArray[], int size, int target);

int main()
{
	int integerArray[ARRAY_SIZE] = { 49, 318, -23, -87, 49, -11, 51, 90, -451, 49 };

	std::cout << "Elements of integerArray:" << std::endl;
	for (int element : integerArray)
		std::cout << element << "\t";

	std::cout << "\n\nOccurencesOfIterative(integerArray, ARRAY_SIZE, 49):" << std::endl;
	std::cout << OccurencesOfIterative(integerArray, ARRAY_SIZE, 49) << std::endl;

	std::cout << "\nOccurencesOfRecursive(integerArray, ARRAY_SIZE, 49):" << std::endl;
	std::cout << OccurencesOfRecursive(integerArray, ARRAY_SIZE, 49) << std::endl;

	std::cin.get();

	return 0;
}

int OccurencesOfIterative(int intArray[], int size, int target)
{
	int count = 0;

	for (int i = 0; i < size; i++)
		if (intArray[i] == target)
			count++;

	return count;
}

int OccurencesOfRecursive(int intArray[], int size, int target)
{
	if (size == 0)
		return 0;

	int occurences = OccurencesOfRecursive(intArray, size - 1, target);

	if (intArray[size - 1] == target)
		occurences++;

	return occurences;
}
