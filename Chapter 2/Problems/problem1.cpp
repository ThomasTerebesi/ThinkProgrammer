// "Problem: Half of a Square", page 26

#include <iostream>

int main()
{
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << "#";
		}
		std::cout << "\n";
	}

	std::cin.get();

	return 0;
}