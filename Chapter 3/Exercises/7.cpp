#include <iostream>
#include <vector>
#include <map>

int main()
{
	int input;
	std::vector<int> intContainer;

	std::cout << "This program will determine number that was entered most frequently." << std::endl;


	// Input
	std::cout << "\nEnter a number: ";
	std::cin >> input;

	while (!std::cin.fail())
	{
		intContainer.push_back(input);
		std::cin.get();

		std::cout << "Enter another number: ";
		std::cin >> input;
	}

	std::cin.clear();
	

	// Processing
	std::map<int, int> histogram;

	for (auto &value : intContainer)
	{
		histogram[value]++;
	}

	int mostFrequent = 0;

	for (auto &iter : histogram)
		if (iter.second > mostFrequent)
			mostFrequent = iter.first;

	std::cout << "\nThe most frequent number is " << mostFrequent << "." << std::endl;

	std::cin.get();
	std::cin.get();
	std::cin.get();

	return 0;
}