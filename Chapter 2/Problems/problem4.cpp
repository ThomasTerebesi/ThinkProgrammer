// "Problem: Count Down by Counting Up", page 28

#include <iostream>

int main()
{
	for (int row = 1; row <= 5; row++)
		std::cout << 6 - row << "\n";

	std::cin.get();

	return 0;
}