#include <iostream>

typedef char * arrayString;

char CharacterAt(arrayString s, int position)
{
	return s[position];
}

int Length(arrayString s)
{
	int count = 0;

	while (s[count] != 0)
		count++;

	return count;
}

void Append(arrayString & s, char c)
{
	int oldLength = Length(s);

	arrayString newString = new char[oldLength + 2];

	for (int i = 0; i < oldLength; i++)
		newString[i] = s[i];

	newString[oldLength] = c;
	newString[oldLength + 1] = 0;

	delete[] s;
	s = newString;
}

void Concatenate(arrayString & s1, arrayString s2)
{
	int oldLength1 = Length(s1);
	int oldLength2 = Length(s2);

	arrayString newString = new char[oldLength1 + oldLength2 + 1];

	for (int i = 0; i < oldLength1; i++)
		newString[i] = s1[i];

	for (int i = 0; i < oldLength2; i++)
		newString[i + oldLength1] = s2[i];

	newString[oldLength1 + oldLength2] = 0;

	delete[] s1;
	s1 = newString;
}

arrayString Substring(const arrayString & s, int start, int length)
{
	if (length > Length(s)) // limit the length to the length of the original string
		length = Length(s);

	arrayString newString = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		newString[i] = s[i + start];
	}

	newString[length] = 0;

	return newString;
}

void ReplaceString(arrayString& source, arrayString target, arrayString replaceText)
{
	int sourceLength = Length(source);
	int targetLength = Length(target);
	int replaceLength = Length(replaceText);
	
	arrayString checkString = new char[1];
	checkString[0] = 0;
	arrayString newString = new char[1];
	newString[0] = 0;

	for (int i = 0; i < sourceLength; i++)
	{
		// If the character does not equal the first target character append source character and break
		if (source[i] != target[0])
		{
			Append(newString, source[i]);
			continue;
		}

		// Store characters in checkString
		for (int j = 0; j < targetLength; j++)
		{
			Append(checkString, source[i + j]);
		}

		// Check whether the string equals target
		if (strcmp(checkString, target) == 0)
		{
			// Append each character of replaceText
			for (int k = 0; k < replaceLength; k++)
				Append(newString, replaceText[k]);
		}
		else
		{
			// Append each character of checkString
			for (int k = 0; k < targetLength; k++)
				Append(newString, checkString[k]);
		}

		delete[] checkString;
		checkString = new char[1];
		checkString[0] = 0;

		i += targetLength - 1;
	}

	delete[] checkString;
	delete[] source;
	source = newString;
}

void ReplaceTester1()
{
	arrayString source = new char[9];
	source[0] = 'a';
	source[1] = 'b';
	source[2] = 'c';
	source[3] = 'd';
	source[4] = 'a';
	source[5] = 'b';
	source[6] = 'e';
	source[7] = 'e';
	source[8] = 0;

	arrayString target = new char[3];
	target[0] = 'a';
	target[1] = 'b';
	target[2] = 0;

	arrayString replaceText = new char[4];
	replaceText[0] = 'x';
	replaceText[1] = 'y';
	replaceText[2] = 'z';
	replaceText[3] = 0;

	std::cout << source << std::endl;

	ReplaceString(source, target, replaceText);

	std::cout << source << std::endl;
}

void ReplaceTester2()
{
	arrayString source = new char[5];
	source[0] = 'a';
	source[1] = 'v';
	source[2] = 'a';
	source[3] = 'b';
	source[4] = 0;

	arrayString target = new char[3];
	target[0] = 'a';
	target[1] = 'b';
	target[2] = 0;

	arrayString replaceText = new char[4];
	replaceText[0] = 'x';
	replaceText[1] = 'y';
	replaceText[2] = 'z';
	replaceText[3] = 0;

	std::cout << source << std::endl;

	ReplaceString(source, target, replaceText);

	std::cout << source << std::endl;
}

int main()
{
	ReplaceTester1();

	std::cout << std::endl;

	ReplaceTester2();

	std::cin.get();

	return 0;
}