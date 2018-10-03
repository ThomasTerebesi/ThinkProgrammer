#include <iostream>
#include "string.h"

int main()
{
	String one("Hello");

	one.Remove(4, -1);

	std::cout << one << std::endl;

	std::cin.get();

	return 0;
}
