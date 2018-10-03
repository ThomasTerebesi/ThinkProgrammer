#pragma once

#include <iostream>

class String
{
public:
	String();
	String(const char* charString);
	String(const String& string);

	~String();

	int GetLength() const;

	void Append(char c);
	void Concatenate(const String& string);
	void Concatenate(const char* charString);
	char CharacterAt(int position);
	void Remove(int start, int n);

	char& operator[](int position);

	friend std::ostream& operator<<(std::ostream& os, const String& string);

private:
	int _length;
	char * _chars;
};