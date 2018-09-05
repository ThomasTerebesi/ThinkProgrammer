#include <iostream>
#include <string>

const short ARRAY_SIZE = 10;

template<typename T>
bool IsArraySorted(T array[], int n);

int main()
{
	// setup
	int intArray[ARRAY_SIZE] = { 12, 14, 50, 78, 90, 93, 99, 107, 116, 133 }; // sorted
	float floatArray[ARRAY_SIZE] = { 3.4f, 21.5f, 16.1f, 33.0f, 92.6f, 87.4f, 54.9f, 22.1f, 87.2f, 11.2f }; // unsorted
	std::string stringArray[ARRAY_SIZE] = { "alpha", "bravo", "charlie", "delta", "echo", "foxtrott", "golf", "hotel", "india", "juliett" }; // sorted
	

	// intArray
	std::cout << "Contents of intArray:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << intArray[i] << "\t";

	if (IsArraySorted(intArray, ARRAY_SIZE))
		std::cout << "\nintArray is sorted!";
	else
		std::cout << "\nintArray is not sorted!";


	// floatArray
	std::cout << "\n\nContents of floatArray:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << floatArray[i] << "\t";

	if (IsArraySorted(floatArray, ARRAY_SIZE))
		std::cout << "\nfloatArray is sorted!";
	else
		std::cout << "\nfloatArray is not sorted!";


	std::string test1 = "alpha";
	std::string test2 = "beta";

	// stringArray
	std::cout << "\n\nContents of stringArray:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << stringArray[i];
		if (i < ARRAY_SIZE - 1)
			std::cout << ", ";
	}

	if (IsArraySorted(stringArray, ARRAY_SIZE))
		std::cout << "\nstringArray is sorted!";
	else
		std::cout << "\nstringArray is not sorted!";

	std::cin.get();

	return 0;
}

template<typename T>
bool IsArraySorted(T array[], int n)
{
	for (int i = 0; i < n - 1; i++)	// 'n - 1' in order to not go out of range
		if (array[i] > array[i + 1])
			return false;

	return true;
}
