// "Problem: Decode a Message", page 41

#include <iostream>
#include <vector>

int main()
{
	std::cout << "Enter a number with as many digits as you like: ";

	char digitChar = std::cin.get();
	int number = (digitChar - '0');
	digitChar = std::cin.get();

	while (digitChar != 10)
	{
		number = number * 10 + (digitChar - '0');
		digitChar = std::cin.get();
	}

	std::cout << "Number entered: " << number << "\n";

	std::cin.get();

	return 0;
}