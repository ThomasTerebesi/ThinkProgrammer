// "Problem: Variable-Length String Manipulation", page 91

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

void Append(arrayString & s, char c) {
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

void ConcatenateTester()
{
	arrayString a = new char[5];
	a[0] = 't';
	a[1] = 'e';
	a[2] = 's';
	a[3] = 't';
	a[4] = 0;

	arrayString b = new char[4];
	b[0] = 'b';
	b[1] = 'e';
	b[2] = 'd';
	b[3] = 0;

	Concatenate(a, b);

	std::cout << a << std::endl;

	arrayString c = new char[5];
	c[0] = 't';
	c[1] = 'e';
	c[2] = 's';
	c[3] = 't';
	c[4] = 0;
	
	arrayString d = new char[1];
	d[0] = 0;
	
	Concatenate(d, c);
	std::cout << c << "\n" << d << "\n";
	std::cout << (void *)c << "\n" << (void *)d << "\n";
}

void AppendTester()
{
	arrayString a = new char[5];

	a[0] = 't';
	a[1] = 'e';
	a[2] = 's';
	a[3] = 't';
	a[4] = 0;

	Append(a, '!');

	std::cout << a << std::endl;

	arrayString b = new char[1];

	b[0] = 0;

	Append(b, '!');

	std::cout << b << std::endl;
}

int main()
{	
	AppendTester();
	ConcatenateTester();

	std::cin.get();

	return 0;
}