#include <iostream>
#include "string.h"

int main()
{
	String one("Hello");
	String two("World");

	one.Append(' ');

	one.Concatenate(two);

	one.Append('!');

	std::cout << one << one.CharacterAt(11) << one[11] << std::endl;

	std::cin.get();

	return 0;
}
