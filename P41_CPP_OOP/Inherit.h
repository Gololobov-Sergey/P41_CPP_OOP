#pragma once
#include<iostream>


using namespace std;

class Human
{
protected:
	string name;
	int age;

public:
	Human() { cout << "Ctor H" << endl; }
	Human(string n, int a) : name(n), age(a) {}
	void info()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}
};


class FootbalPlayer : public Human
{
	int number;

public:
	FootbalPlayer()
	{

	}
	FootbalPlayer(string n, int a, int num) : number(num), Human(n, a)
	{
		/*cout << "Ctor FP" << endl;*/
	}

	void info()
	{
		Human::info();
		cout << "Number  : " << number << endl;
	}

};

class Forward : public FootbalPlayer
{
	int goals;


};


class A
{
	int a1;

protected:
	int a2;

public:
	int a3;

	void aa() {}
};

class B : private A
{
	int b1;

protected:
	int b2;

public:
	int b3;

	void bb()
	{
		//a1; // error
		//a2;
		//a3;
		aa();
	}
};




class Device
{
protected:
	int id;

public:
	Device(int id) : id(id) {}
};


class LAN : virtual public Device
{

public:
	LAN(int id) : Device(id){}

	int getID() { return id; }
};


class WiFi : virtual public Device
{

public:
	WiFi(int id) : Device(id) {}

	int getID() { return id; }
};


class Router : public LAN, public WiFi
{
public:
	Router(int id) : LAN(id), WiFi(id), Device(id) {}
};