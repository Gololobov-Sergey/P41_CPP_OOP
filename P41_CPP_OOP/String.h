#pragma once

class String
{
	char* str;
	int size;

	static int totalObjects;

public:

	String();

	explicit String(int size);

	String(const char* str);

	~String();

	void set(const char* str);

	void set();

	char* get() const;

	static int length(const char* str);

	int length() const;

	static int getTotalObjects();
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
	this->set(str);
	totalObjects++;
}

String::~String()
{
	delete[] str;
	totalObjects--;
}

void String::set(const char* str)
{
	delete[] this->str;

	size = String::length(str);
	this->str = new char[size + 1];
	for (size_t i = 0; i <= size; i++)
	{
		this->str[i] = str[i];
	}
}

void String::set()
{
	char buff[8000];
	cin.getline(buff, 8000);

	this->set(buff);
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

inline int String::getTotalObjects()
{
	return totalObjects;
}
