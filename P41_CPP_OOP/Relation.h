#pragma once
#include <iostream>

using namespace std;


class Engine1
{
	int power = 50;

public:
	Engine1() { cout << "Engine" << endl; }
	~Engine1() { cout << "~Engine" << endl; }
	void setPower(int p)
	{
		power = p;
	}

	int getPower()
	{
		return power;
	}
};

class Car1
{
	Engine1 engine;

public:
	Car1() { cout << "Car" << endl; }
	~Car1() { cout << "~Car" << endl; }
	
};


class Car2
{
	Engine1* engine;

public:
	Car2(Engine1* en) { engine = en; cout << "Car2 create" << endl; }
	~Car2() { cout << "~Car2" << endl; }

	Engine1* getEngine()
	{
		Engine1* en = engine;
		engine = nullptr;
		return en;
	}

	void setEngine(Engine1* en)
	{
		engine = en;
	}

	void info()
	{
		if(engine)
			cout << "Power - " << engine->getPower() << endl;
		else
		{
			cout << "Engine not found" << endl;
		}
	}
};


class STO
{
	Engine1* engine;

public:
	void setEngineToStend(Engine1* en)
	{
		engine = en;
	}

	void upPower(int p)
	{
		engine->setPower(p);
	}

	Engine1* getEngine()
	{
		return engine;
	}
};