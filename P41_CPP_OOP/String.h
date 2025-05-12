#pragma once
#include <iostream>

using namespace std;

class String
{
	char* str = nullptr;
	int size;

	static int totalObjects;

public:

	String();

	explicit String(int size);

	String(const char* str);

	String(const String& obj);

	String& operator=(const String& obj);

	~String();

	void set(const char* str);

	void set();

	char* get() const;

	static int length(const char* str);

	int length() const;

	static int getTotalObjects();

	void operator()(const char* st);

	void operator+=(String st);

	String operator+(const String& st);

	friend ostream& operator<< (ostream& out, const String& obj);
	friend istream& operator>> (istream& in, String& obj);

	bool operator==(const String& obj) const;
	bool operator>(const String& obj) const;
	bool operator<(const String& obj) const;
};

int String::totalObjects = 0;


String::String() : String(0) {}

String::String(int size)
{
	this->size = size;
	str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		str[i] = ' ';
	}
	str[size] = '\0';
	totalObjects++;
}

String::String(const char* str)
{
	//cout << "Constructor" << endl;
	this->set(str);
	totalObjects++;
}

String::String(const String& obj)
{
	//cout << "Copy Constructor" << endl;
	size = obj.size;
	str = new char[size + 1];
	for (size_t i = 0; i <= size; i++)
	{
		str[i] = obj.str[i];
	}
	totalObjects++;
}

String& String::operator=(const String& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (str != nullptr)
	{
		delete str;
	}

	size = obj.size;
	str = new char[size + 1];
	for (size_t i = 0; i <= size; i++)
	{
		str[i] = obj.str[i];
	}

	return *this;
}


String::~String()
{
	//cout << "Destructor" << endl;
	delete str;
	totalObjects--;
}

void String::set(const char* str)
{
	delete this->str;

	size = String::length(str);
	this->str = new char[size + 1];
	for (size_t i = 0; i <= size; i++)
	{
		this->str[i] = str[i];
	}
}


char* String::get() const
{
	return str;
}

int String::length(const char* str)
{
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return count;

}

int String::length() const
{
	return size;
}

int String::getTotalObjects()
{
	return totalObjects;
}

void String::operator()(const char* st)
{
	this->set(st);
}

void String::operator+=(String st)
{
	*this = *this + st;
}

String String::operator+(const String& st)
{
	char* temp = new char[size + st.size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = str[i];
	}
	for (size_t i = 0; i <= st.size; i++)
	{
		temp[i + size] = st.str[i];
	}
	return String(temp);
}

bool String::operator==(const String& obj) const
{
	if (this == &obj)
	{
		return true;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (str[i] != obj.str[i])
		{
			return false;
		}
	}
	return true;
}

inline bool String::operator>(const String& obj) const
{
	return strcmp(str, obj.str) > 0;
}

inline bool String::operator<(const String& obj) const
{
	return strcmp(str, obj.str) < 0;
}


ostream& operator<< (ostream& out, const String& obj)
{
	out << obj.str;
	return out;
}

inline istream& operator>>(istream& in, String& obj)
{
	char buff[8000];
	cin.getline(buff, 8000);

	obj.set(buff);

	return in;
}
