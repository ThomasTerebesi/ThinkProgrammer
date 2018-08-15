// "Problem: Luhn Checksum Validation", page 31

#include <iostream>

int doubleDigitValue(int digit);

int main()
{
	char digit;
	int oddChecksum = 0;
	int evenChecksum = 0;
	int position = 1;

	std::cout << "Enter a number: ";
	
	digit = std::cin.get();

	while (digit != 10)
	{
		std::cin >> digit;

		if (position % 2 == 0)
		{
			oddChecksum += doubleDigitValue(digit - '0');
			evenChecksum += digit - '0';
		}
		else
		{
			oddChecksum += digit - '0';
			evenChecksum += doubleDigitValue(digit - '0');
		}

		digit = std::cin.get();
		position++;
	}
	
	int checksum;

	(position - 1) % 2 == 0 ? checksum = evenChecksum : checksum = oddChecksum;

	std::cout << "Checksum is " << checksum << "." << std::endl;
	
	if (checksum % 10 == 0)
		std::cout << "Checksum is divisible by 10. Valid." << std::endl;
	else
		std::cout << "Checksum is not divisible by 10. Invalid." << std::endl;


	std::cin.get();
	std::cin.get();

	return 0;
}

int doubleDigitValue(int digit)
{
	int doubledDigit = digit * 2;
	int sum;

	if (doubledDigit > 10)
		sum = 1 + doubledDigit % 10;
	else
		sum = doubledDigit;

	return sum;
}
