// Exercise 5, page 54

#include <iostream>

void CheckValidity();
void GenerateCheckDigit();

int main()
{
	CheckValidity();
	GenerateCheckDigit();

	std::cin.get();

	return 0;
}

void CheckValidity()
{
	char digit;
	int checksum = 0;
	int position = 1;

	std::cout << "Enter an ISBN-13 (without hyphens) to be checked for its validity: ";

	digit = std::cin.get();

	while (digit != 10)
	{
		if (position % 2 == 0)
			checksum += (digit - '0') * 3;
		else
			checksum += digit - '0';

		digit = std::cin.get();
		position++;
	}

	std::cout << "Your ISBN-13 is " << (checksum % 10 == 0 ? "valid." : "invalid.") << " (Checksum: " << checksum << ")" << std::endl;
}

void GenerateCheckDigit()
{
	char digit;
	int sum = 0;
	int position = 1;

	std::cout << "\nEnter the twelve first digits of an ISBN-13 (without hyphens) to calculate its check digit: ";

	digit = std::cin.get();

	while (digit != 10 && position < 13)
	{
		if (position % 2 == 0)
		{
			sum += (digit - '0') * 3;
		}
		else
		{
			sum += digit - '0';
		}

		digit = std::cin.get();
		position++;
	}

	std::cout << "Your ISBN-13's check digit is " << (10 - (sum % 10) == 10 ? 0 : 10 - (sum % 10)) << "." << std::endl;
}
