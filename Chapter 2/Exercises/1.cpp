// Exercise 1, page 53
#include <iostream>

int main()
{
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

