#include <iostream>

int Factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main()
{
	for (int i = 0; i < 9; i++)
		std::cout << i << "! = " << Factorial(i) << std::endl;
	 
	std::cin.get();

	return 0;
}