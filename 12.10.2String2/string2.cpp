// string1.cpp -- String class methods
#pragma warning(disable : 4996)
#include <cstring>                 // string.h for some
#include <cctype>
#include "string2.h"               // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
	return num_strings;
}

// class methods
String::String(const char* s)     // construct String from C string
{
	len = std::strlen(s);          // set size
	str = new char[len + 1];       // allot storage
	std::strcpy(str, s);           // initialize pointer
	num_strings++;                 // set object count
	cout << "构造函数1\n";
}

String::String()                   // default constructor
{
	len = 4;
	str = new char[1];
	str[0] = '\0';                 // default string
	num_strings++;
		cout << "构造函数2\n";
}

String::String(const String& st)
{
	num_strings++;             // handle static member update
	len = st.len;              // same length
	str = new char[len + 1];  // allot space
	std::strcpy(str, st.str);  // copy string to new location
	cout << "复制构造函数\n";
}

String::~String()                     // necessary destructor
{
	--num_strings;                    // required
	delete[] str;                    // required
	cout << "构x函数\n";
}

// overloaded operator methods    

	// assign a String to a String
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// assign a C string to a String
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// read-write char access for non-const String
char& String::operator[](int i)
{
	return str[i];
}

// read-only char access for const String
const char& String::operator[](int i) const
{
	return str[i];
}

// overloaded operator friends

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

// quick and dirty String input
istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

String String::operator+(const String& s) const
{
	String NewStr;

	NewStr.len = strlen(str) + strlen(s.str);
	NewStr.str = new char[NewStr.len + 1];

	strcpy(NewStr.str, str);
	strcat(NewStr.str, s.str);

	return NewStr;
}

String String::operator+(const char* c)  const
{
	//String NewStr;

	//NewStr.len = strlen(str) + strlen(c);
	//NewStr.str = new char[NewStr.len + 1];

	//strcpy(NewStr.str, str);
	//strcat(NewStr.str, c);

	//return NewStr;

	String TempStr(c);

	return (*this) + TempStr;
}

void String::stringlow(void)
{
	for (int i = 0; (*this)[i] != '\0'; i++)
	{
		(*this)[i] = tolower((*this)[i]);
	}
}

void String::stringup(void)
{
	for (int i = 0; (*this)[i] != '\0'; i++)
	{
		(*this)[i] = toupper((*this)[i]);
	}
}

int String::has(const char s) const
{
	int xC = 0;
	for (int i = 0; (*this)[i] != '\0'; i++)
	{
		if ((*this)[i] == s)
			xC++;
	}

	return xC;
}

String operator+(const char* c, const String& s)
{
	String TempStr = c;

	return TempStr + s;
}