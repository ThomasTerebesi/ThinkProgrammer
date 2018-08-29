// Exercise 6, page 54
#include <iostream>


int main()
{
	int decimal, i, j;
	unsigned short binary[32];

	std::cout << "Enter a decimal number (or 'q' to quit): ";

	while (std::cin >> decimal)
	{
		i = 0;

		std::cout << "The binary representation of " << decimal << " is ";

		do
		{
			binary[i++] = decimal % 2;
			decimal /= 2;
		} while (decimal != 0);

		for (j = i - 1; j >= 0; j--)
			std::cout << binary[j];

		std::cout << ".\n\nEnter another decimal number (or 'q' to quit): ";
	}

	std::cin.get();
	std::cin.get();

	return 0;
}