// "Problem: A Sideways Triangle", page 29

#include <iostream>

int main()
{
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 4 - abs(4 - i); j++)
		{
			std::cout << "#";
		}
		std::cout << "\n";
	}

	std::cin.get();

	return 0;
}