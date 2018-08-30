#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter something:" << std::endl;

	std::string word;
	std::string longest = "";
	unsigned short count = 0;

	while (std::cin >> word)
	{
		std::cout << word << ", " << count << std::endl;
		count++;

		if (word.length() > longest.length())
			longest = word;

		// TODO: Greatest number of vowels
		// TODO: Make loop stop at some point
	}

	std::cout << count << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}