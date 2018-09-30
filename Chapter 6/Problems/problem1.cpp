// "Problem: Computing the Sum of an Array of Integers", page 153

#include <iostream>

const int ARRAY_SIZE = 10;

int IterativeArraySum(int integers[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += integers[i];

	return sum;
}

int ArraySumRecursive(int integers[], int size)
{
	if (size == 0)
		return 0;

	int lastNumber = integers[size - 1];
	int allButLastSum = ArraySumRecursive(integers, size - 1);

	return lastNumber + allButLastSum;
}

int main()
{
	int a[ARRAY_SIZE] = { 20, 3, 5, 22, 7, 9, 14, 17, 4, 9 };

	std::cout << IterativeArraySum(a, ARRAY_SIZE) << std::endl;
	std::cout << ArraySumRecursive(a, ARRAY_SIZE) << std::endl;

	std::cin.get();

	return 0;
}