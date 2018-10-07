#include <iostream>

const int ARRAY_SIZE = 10;

int SumOfPositiveIterative(const int intArray[], int size);
int SumOfPositiveRecursive(const int intArray[], int size);

int main()
{
	int integerArray[ARRAY_SIZE] = { 2, 318, -23, -87, 38, -11, 51, 90, -451, 49 };

	std::cout << "SumOfPositiveIterative(integerArray, ARRAY_SIZE):" << std::endl;
	std::cout << SumOfPositiveIterative(integerArray, ARRAY_SIZE) << std::endl;
	
	std::cout << "\nSumOfPositiveRecursive(integerArray, ARRAY_SIZE):" << std::endl;
	std::cout << SumOfPositiveRecursive(integerArray, ARRAY_SIZE) << std::endl;

	std::cin.get();

	return 0;
}

int SumOfPositiveIterative(const int intArray[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
		if (intArray[i] > 0)
			sum += intArray[i];

	return sum;
}

int SumOfPositiveRecursive(const int intArray[], int size)
{
	if (size == 0)
		return 0;

	int lastNumber = intArray[size - 1] > 0 ? intArray[size - 1] : 0;
	int allButLastSum = SumOfPositiveRecursive(intArray, size - 1);

	return lastNumber + allButLastSum;
}
