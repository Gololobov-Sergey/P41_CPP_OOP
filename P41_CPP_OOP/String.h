#pragma once

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
		delete[] str;
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
