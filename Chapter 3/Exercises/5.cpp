#include <iostream>
#include <cctype>
#include <string>

const char cipherArray[26]{ 'P', 'H', 'Q', 'G', 'I', 'U', 'M', 'E',
							'A', 'Y', 'L', 'N', 'O', 'F', 'D', 'X',
							'J', 'K', 'R', 'C', 'V', 'S', 'T', 'Z',
							'W', 'B' };

int main()
{
	std::cout << "Enter plaintext to encrypt it: ";

	char inputChar;
	inputChar = std::cin.get();

	std::string originalInput = "";

	std::cout << "Your encrypted text: ";

	while (inputChar != 10)
	{
		originalInput += inputChar;

		if (isspace(inputChar))
			std::cout << ' ';
		else if (isalpha(inputChar))
		{
			inputChar = toupper(inputChar);
			std::cout << cipherArray[inputChar - 'A'];
		}
		else
			std::cout << inputChar;

		inputChar = std::cin.get();
	}


	// now check

	std::cout << "\n\n" << originalInput << std::endl;

	std::cin.get();

	return 0;
}