#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>


const int CIPHER_SIZE = 26;

const char cipherArray[CIPHER_SIZE]{ 'P', 'H', 'Q', 'G', 'I', 'U', 'M', 'E',
									 'A', 'Y', 'L', 'N', 'O', 'F', 'D', 'X',
									 'J', 'K', 'R', 'C', 'V', 'S', 'T', 'Z',
									 'W', 'B' };

int main()
{
	std::cout << "Enter plaintext to encrypt it: ";

	char inputChar;
	inputChar = std::cin.get();

	std::string originalInput = "";
	std::string encryptedText = "";

	std::cout << "Your encrypted text: ";


	// Encryption 
	while (inputChar != 10)
	{
		originalInput += inputChar;

		if (isspace(inputChar))
			encryptedText += ' ';
		else if (isalpha(inputChar))
		{
			inputChar = toupper(inputChar);
			encryptedText += cipherArray[inputChar - 'A'];
		}
		else
			encryptedText += inputChar;

		inputChar = std::cin.get();
	}

	std::cout << encryptedText << std::endl;


	// Decryption
	std::string decryptedText = "";

	for (int i = 0; i < encryptedText.size(); i++)
	{
		if (isspace(encryptedText[i]))
			decryptedText += ' ';
		else if (isalpha(encryptedText[i]))
		{
			for (int j = 0; j < CIPHER_SIZE; j++)
			{
				if (encryptedText[i] == cipherArray[j])
				{
					decryptedText += toupper(static_cast<char>('A' + j));
					continue;
				}
			}
		}
		else
			decryptedText += encryptedText[i];
	}


	// Verification
	std::transform(originalInput.begin(), originalInput.end(), originalInput.begin(), toupper);
	
	if (originalInput == decryptedText)
		std::cout << "Encryption and decryption were successful." << std::endl;
	else
		std::cout << "Encryption and decryption were not successful." << std::endl;


	std::cin.get();

	return 0;
}