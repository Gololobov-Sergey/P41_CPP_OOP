#pragma once
#include<iostream>


using namespace std;


class IPrintable
{
public:
	virtual ~IPrintable() {}

	virtual void print() = 0;
};



class Animal
{
	string name;
	int age;

public:
	Animal(string n, int a) : name(n), age(a) {}

	virtual ~Animal() { cout << "Destr Animal" << endl; }

	virtual string getType()
	{
		return "Animal";
	}

	void info()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	virtual string voice() = 0;

};


string Animal::voice()
{
	return "No voice";
}

class Cat /*final*/: public Animal, public IPrintable
{
	int mouse = 5;

public:
	Cat(string n, int a) : Animal(n, a) {}

	virtual ~Cat() { cout << "Destr Cat" << endl; }

	virtual string getType() override
	{
		return "Cat";
	}

	virtual int getMouse()
	{
		return mouse;
	}

	virtual string voice() override /*final*/
	{
		return "Mau Mau";
	}

	virtual void print() override
	{
		cout << getType() << endl;
		cout << voice() << endl;
	}
};


class SiamCat : public Cat
{
public:
	SiamCat(string n, int a) : Cat(n, a) {}

	virtual string getType() override
	{
		return "SiamCat";
	}

	virtual string voice() override
	{
		return "Myau Gaw Myau";
	}
};


class Dog : public Animal
{
public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() override
	{
		return "Dog";
	}

	virtual string voice() override
	{
		return "Gaw Gaw";
	}
};

class Parrot : public Animal
{
public:
	Parrot(string n, int a) : Animal(n, a) {}

	virtual string getType() override
	{
		return "Parrot";
	}

	virtual string voice() override
	{
		return "Kar Kar - Gaw Mau";
	}
};


class Ulitka : public Animal
{
public:
	Ulitka(string n, int a) : Animal(n, a) {}

	virtual string getType() override
	{
		return "Ulitka";
	}

	virtual string voice() override
	{
		return Animal::voice();
	}
};