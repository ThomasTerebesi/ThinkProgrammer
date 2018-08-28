// Exercise 4, page 54
#include <iostream>

void PrintSquare(unsigned int length);

int main()
{
	std::cout << "Enter the length of the square's sides ('q' to quit): ";

	unsigned int input;
	while (std::cin >> input)
	{
		std::cout << std::endl;
		PrintSquare(input);

		std::cout << "\nEnter the length of the square's sides ('q' to quit): ";
	}

	std::cin.get();
	std::cin.get();

	return 0;
}

void PrintSquare(unsigned int length)
{
	for (int row = 0; row < length; row++)
	{
		if (row == 0 || row == length - 1)
		{
			for (int i = 0; i < length; i++)
				std::cout << "# ";
			std::cout << std::endl;
		}
		else
		{
			std::cout << "# ";
			for (int i = 0; i < length - 2; i++)
				std::cout << "  ";
			std::cout << "# " << std::endl;
		}
	}
}
