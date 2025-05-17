#pragma once
#include<iostream>


using namespace std;

class Human
{

	string name;
	int age;

public:
	Human() {}
	Human(string n, int a) : name(n), age(a) {}
	void info()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}
};


class FootbalPlayer : public Human
{
	


};
