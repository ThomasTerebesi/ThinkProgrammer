// "Problem: Finding the Mode", page 62

#include <iostream>

const int ARRAY_SIZE = 12;

int compareFunc(const void* voidA, const void* voidB)
{
	int * intA = (int *)(voidA);
	int * intB = (int *)(voidB);
	return *intA - *intB;
}

int main()
{
	int surveyData[ARRAY_SIZE] = { 4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10 };

	std::cout << "Contents of surveyData:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << surveyData[i] << "\t";

	qsort(surveyData, ARRAY_SIZE, sizeof(int), compareFunc);

	int mostFrequent;
	int highestFrequency = 0;
	int currentFrequency = 0;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		currentFrequency++;

		if (i == ARRAY_SIZE - 1 || surveyData[i] != surveyData[i + 1])
		{
			if (currentFrequency > highestFrequency)
			{
				highestFrequency = currentFrequency;
				mostFrequent = surveyData[i];
			}

			currentFrequency = 0;
		}
	}

	std::cout << "\n\nMode of surveyData:\n" << mostFrequent << std::endl;

	std::cin.get();

	return 0;
}