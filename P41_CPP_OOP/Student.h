#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	int id;
	char* name;
	int age;

public:
	Student()
	{
		//cout << "Constructor" << endl;
		id = 0;
		setName("No Name");	
		setAge(10);
	}

	Student(int i, const char* n, int a)
	{
		//cout << "Constructor 3 param" << endl;
		id = i;
		setName(n);
		setAge(a);
	}

	void setAge(int a)
	{
		if (a < 10 || a > 50)
			return;
		age = a;
	}

	int getAge()
	{
		return age;
	}

	void setName(const char* n)
	{
		if (n != nullptr)
		{
			if (name != nullptr)
				delete[] name;
			name = new char[strlen(n) + 1];
			strcpy_s(name, strlen(n) + 1, n);
		}
	}

	const char* getName()
	{
		return name;
	}

	void print()
	{
		cout << "ID  : " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Age : " << age << endl;
	}
};