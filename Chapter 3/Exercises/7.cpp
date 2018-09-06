#include <iostream>
#include <vector>

int main()
{
	int input;
	std::vector<int> intContainer;

	std::cin >> input;

	while (std::cin >> input)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			break;
		}

		intContainer.push_back(input);
		std::cin.get();
	}

	

	for (int number : intContainer)
		std::cout << number << std::endl;


	return 0;
}