#pragma once
#include <iostream>

using namespace std;

enum class TYPE{ INT, DOUBLE, STRING };

class var
{
	void* val;

	TYPE type;

public:
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

