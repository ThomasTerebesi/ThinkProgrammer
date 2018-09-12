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

	arrayString newS = new char[oldLength + 2];

	for (int i = 0; i < oldLength; i++)
		newS[i] = s[i];

	newS[oldLength] = c;
	newS[oldLength + 1] = 0;

	delete[] s;
	s = newS;
}

void Concatenate(arrayString & s1, arrayString s2)
{
	int oldLength1 = Length(s1);
	int oldLength2 = Length(s2);

	arrayString newS = new char[oldLength1 + oldLength2 + 1];

	for (int i = 0; i < oldLength1; i++)
		newS[i] = s1[i];

	for (int i = 0; i < oldLength2; i++)
		newS[i + oldLength1] = s2[i];

	newS[oldLength1 + oldLength2] = 0;

	delete[] s1;
	s1 = newS;
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

arrayString ReplaceString(arrayString& source, arrayString target, arrayString replaceText)
{

}



int main()
{


	std::cin.get();

	return 0;
}