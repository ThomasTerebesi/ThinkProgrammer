// Exercise 3, page 54
#include <iostream>

int main()
{
	// Upper half
	for (int row = 0; row < 4; row++)
	{
		// Upper left
		for (int space = 0; space < row; space++)
			std::cout << ' ';

		for (int column = 0; column < row + 1; column++)
			std::cout << '#';

		// Upper right
		for (int space = 0; space < (3 - row) * 4; space++)
			std::cout << ' ';

		for (int column = 0; column < row + 1; column++)
			std::cout << '#';
		std::cout << std::endl;
	}

	// Lower half
	for (int row = 0; row < 4; row++)
	{
		// Lower left
		for (int space = 0; space < (3 - row); space++)
			std::cout << ' ';

		for (int column = 0; column < 4 - row; column++)
			std::cout << '#';

		// Lower right
		for (int space = 0; space < row * 4; space++)
			std::cout << ' ';

		for (int column = 0; column < 4 - row; column++)
			std::cout << '#';

		std::cout << std::endl;
	}

	std::cin.get();

	return 0;
}