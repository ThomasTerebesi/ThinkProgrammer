#include <iostream>

typedef char * arrayString;

char CharacterAt(arrayString s, int position)
{
	// Doesn't have a tester function, but behaves the same as before
	return s[position + 1];
}

void Append(arrayString & s, char c)
{
	int oldLength = static_cast<int>(s[0] - '0');

	arrayString newS = new char[oldLength];

	for (int i = 0; i < oldLength; i++)
		newS[i] = s[i];

	newS[oldLength] = c;
	newS[0]++;

	delete[] s;
	s = newS;
}

void Concatenate(arrayString & s1, arrayString s2)
{
	int oldLength1 = static_cast<int>(s1[0] - '0');
	int oldLength2 = static_cast<int>(s2[0] - '0');

	arrayString newS = new char[oldLength1 + oldLength2 + 1];

	newS[0] = oldLength1 + oldLength2 - 1 + '0';

	for (int i = 1; i < oldLength1; i++)
		newS[i] = s1[i];

	for (int i = 1; i < oldLength2; i++)
		newS[i + oldLength1 - 1] = s2[i];

	delete[] s1;
	s1 = newS;
}

void Output(arrayString & s)
{
	for (int i = 1; i < static_cast<int>(s[0] - '0'); i++)
		std::cout << s[i];

	std::cout << std::endl;
}

void ConcatenateTester()
{
	arrayString a = new char[5];
	a[0] = '5';
	a[1] = 't';
	a[2] = 'e';
	a[3] = 's';
	a[4] = 't';

	arrayString b = new char[4];
	b[0] = '4';
	b[1] = 'b';
	b[2] = 'e';
	b[3] = 'd';

	Concatenate(a, b);

	Output(a);
}

void AppendTester()
{
	arrayString a = new char[5];
	a[0] = '5';
	a[1] = 't';
	a[2] = 'e';
	a[3] = 's';
	a[4] = 't';

	Append(a, '!');

	Output(a);
}

int main()
{
	AppendTester();

	ConcatenateTester();

	std::cin.get();

	return 0;
}