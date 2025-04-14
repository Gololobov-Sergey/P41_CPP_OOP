#pragma once
#include <iostream>

#include "Array.h"
#include "String.h"

using namespace std;

class Student
{
private:
	int id;
	String name;
	int age;

	const int count;

	static int planet;

	Array<int> marks;

public:

	static int totalObjects;

	Student() : Student(0, "No Name", 10, 0)
	{
		//cout << "Constructor" << endl;
		//setName("No Name");	
		//setAge(10);
		//totalObjects++;
	}

	Student(int i, const char* n, int a, int c) : count{ c }, id(i)
	{
		cout << "Constructor 3 param" << endl;
		setName(n);
		setAge(a);

		totalObjects++;
	}

	~Student()
	{
		cout << "Destructor" << endl;
		/*if (name != nullptr)
			delete[] name;*/

		totalObjects--;
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
		name.set(n);
	}

	char* getName()
	{
		return name.get();
	}

	void print()
	{
		cout << "ID  : " << id << endl;
		cout << "Name: " << name.get() << endl;
		cout << "Age : " << age << endl;
	}

	int getCount()
	{
		return count;
	}	

	static int getPlanet()
	{
		return planet;
	}

	static void setPlanet(int p)
	{
		//age = 10000000;

		if (/*цю планету колонізовано*/ false)
		{
			planet = p;
		}
	}

	void addMark(int mark)
	{
		marks.add(mark);
	}
};

int Student::planet = 3;

int Student::totalObjects = 0;