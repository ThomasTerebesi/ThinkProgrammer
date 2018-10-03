#include "string.h"

String::String()
	: _chars(nullptr), _length(0)
{
}

String::String(const char * charString)
{
	_length = 0;

	while (charString[_length] != 0)
		_length++;

	_chars = new char[_length + 1];

	for (int i = 0; i < _length + 1; i++)
		_chars[i] = charString[i];
}

String::String(const String & string)
{
	_length = 0;

	while (string._chars[_length] != 0)
		_length++;

	_chars = new char[_length + 1];

	for (int i = 0; i < _length + 1; i++)
		_chars[i] = string._chars[i];
}

String::~String()
{
	if (_chars != nullptr)
		delete _chars;
}

int String::GetLength() const
{
	return _length;
}

void String::Append(char c)
{
	int newLength = _length + 1;

	char * newString = new char[newLength + 1];

	for (int i = 0; i < _length; i++)
		newString[i] = _chars[i];

	newString[_length] = c;
	newString[_length + 1] = 0;

	delete _chars;

	_chars = newString;
	_length = newLength;
}

void String::Concatenate(const String & string)
{
	int otherLength = string.GetLength();
	int newLength = _length + otherLength;

	char * newString = new char[newLength + 1];

	for (int i = 0; i < _length; i++)
		newString[i] = _chars[i];

	for (int i = 0; i < otherLength; i++)
		newString[i + _length] = string._chars[i];

	newString[newLength] = 0;

	delete _chars;

	_chars = newString;
	_length = newLength;
}

void String::Concatenate(const char * charString)
{
	int otherLength = 0;

	while (charString[otherLength] != 0)
		otherLength++;

	int newLength = _length + otherLength;

	char * newString = new char[newLength + 1];

	for (int i = 0; i < _length; i++)
		newString[i] = _chars[i];

	for (int i = 0; i < otherLength; i++)
		newString[i + _length] = charString[i];

	newString[newLength] = 0;

	delete _chars;

	_chars = newString;
	_length = newLength;
}

char String::CharacterAt(int position)
{
	return _chars[position];
}

char & String::operator[](int position)
{
	return _chars[position];
}

std::ostream & operator<<(std::ostream & os, const String& string)
{
	os << string._chars;

	return os;
}
