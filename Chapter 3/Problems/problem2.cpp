// "Refactoring", page 55

#include <iostream>

const int ARRAY_SIZE = 12;
const int MAX_RESPONSE = 10;

int main()
{
	int surveyData[ARRAY_SIZE] = { 4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10 };
	int histogram[MAX_RESPONSE];
	int mostFrequent = 0;

	std::cout << "Contents of surveyData:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << surveyData[i] << "\t";

	// Using a histogram
	for (int i = 0; i < MAX_RESPONSE; i++)
		histogram[i] = 0;

	for (int i = 0; i < ARRAY_SIZE; i++)
		histogram[surveyData[i] - 1]++;

	for (int i = 1; i < MAX_RESPONSE; i++)
		if (histogram[i] > histogram[mostFrequent])
			mostFrequent = i;

	mostFrequent++;

	std::cout << "\n\nMode of surveyData:\n" << mostFrequent << std::endl;

	std::cin.get();

	return 0;
}
