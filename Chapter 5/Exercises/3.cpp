#include <iostream>

class String
{
public:
	String();
	String(const char* charString);

	~String();
	
	int GetLength();

	void Append();
	void Concatenate();
	char CharacterAt();

	String& operator=(String& string);
	String& operator=(const char* charString);

private:
	int _length;
	char * _chars;
};

int main()
{


	std::cin.get();

	return 0;
}