#pragma once
#include <iostream>

using namespace std;

enum class TYPE{ INT, DOUBLE, STRING };

class var
{
	void* val;

	TYPE type;

public:
	var()
	{

	}

	var(int value)
	{
		type = TYPE::INT;
		val = new int(value);
	}

	var(double value)
	{
		type = TYPE::DOUBLE;
		val = new double(value);
	}

	var(const char* value)
	{
		type = TYPE::STRING;
		val = new char[strlen(value) + 1];
		strcpy_s((char*)val, strlen(value) + 1, value);
	}

	~var()
	{
		delete val;
	}

	var& operator=(const var& obj)
	{
		if (this == &obj)
			return *this;

		if (val != nullptr)
			delete val;

		type = obj.type;
		switch (type)
		{
		case TYPE::INT:    val = new int(*((int*)obj.val)); break;
		case TYPE::DOUBLE: val = new double(*((double*)obj.val)); break;
		case TYPE::STRING:
			val = new char[strlen((char*)obj.val) + 1];
			strcpy_s((char*)val, strlen((char*)obj.val) + 1, (char*)obj.val);
			break;
		}

		return *this;
	}

	var& operator=(const char* obj)
	{
		if (val != nullptr)
			delete val;

		type = TYPE::STRING;
		val = new char[strlen(obj) + 1];
		strcpy_s((char*)val, strlen(obj) + 1, obj);

		return *this;
	}

	void print()
	{
		switch (type)
		{
		case TYPE::INT:
			cout << *((int*)val) << endl;
			break;
		case TYPE::DOUBLE:
			cout << *((double*)val) << endl;
			break;
		case TYPE::STRING:
			cout << (char*)val << endl;
			break;
		}

	}
};

