// Exercise 2, page 54
#include <iostream>

int main()
{
	// Upper half
	for (int row = 0; row < 4; row++)
	{
		for (int space = 0; space <= 2 - row; space++)
			std::cout << ' ';

		for (int column = 0; column < 2 + row * 2; column++)
			std::cout << '#';
		std::cout << std::endl;
	}

	// Lower half
	for (int row = 0; row < 4; row++)
	{
		for (int space = 0; space < row; space++)
			std::cout << ' ';

		for (int column = 0; column < 8 - row * 2; column++)
			std::cout << '#';
		std::cout << std::endl;
	}

	std::cin.get();

	return 0;
}