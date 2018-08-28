// "Problem: Decode a Message", page 41
// Example input from the book: "18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10,-1"

#include <iostream>

int main()
{
	std::cout << "Enter some numbers (end the sequence with '-1'): ";

	char outputCharacter;
	enum modeType { UPPERCASE, LOWERCASE, PUNCTUATION };
	modeType mode = UPPERCASE;
	char digitChar;

	do
	{
		digitChar = std::cin.get();
		
		int number = (digitChar - '0');
		
		digitChar = std::cin.get();
		
		while ((digitChar != 10) && (digitChar != ','))
		{
			number = number * 10 + (digitChar - '0');
			digitChar = std::cin.get();
		}
		
		switch (mode)
		{
		case UPPERCASE:
			number = number % 27;
			outputCharacter = number + 'A' - 1;
			
			if (number == 0)
			{
				mode = LOWERCASE;
				continue;
			}

			break;
		case LOWERCASE:
			number = number % 27;
			outputCharacter = number + 'a' - 1;
			
			if (number == 0)
			{
				mode = PUNCTUATION;
				continue;
			}

			break;
		case PUNCTUATION:
			number = number % 9;
			
			switch (number)
			{
			case 1: 
				outputCharacter = '!'; 
				break;
			case 2: 
				outputCharacter = '?'; 
				break;
			case 3: 
				outputCharacter = ','; 
				break;
			case 4: 
				outputCharacter = '.'; 
				break;
			case 5: 
				outputCharacter = ' '; 
				break;
			case 6: 
				outputCharacter = ';'; 
				break;
			case 7: 
				outputCharacter = '"'; 
				break;
			case 8: 
				outputCharacter = '\''; 
				break;
			}
			
			if (number == 0)
			{
				mode = UPPERCASE;
				continue;
			}

			break;
		}
		
		std::cout << outputCharacter;

	} while (digitChar != 10);

	std::cout << "\n";

	std::cin.get();

	return 0;
}