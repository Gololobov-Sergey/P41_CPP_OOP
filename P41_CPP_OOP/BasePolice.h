#pragma once
#include"String.h"
#include "List.h"
#include "BTree.h"

class Protocol
{
	String numTZ;
	String date;
	String tag;
	int summa;
	bool isPay = false;

public:
	String getNumTZ()
	{
		return numTZ;
	}

	friend istream& operator>>(istream& in, Protocol* p);
	friend ostream& operator<<(ostream& out, const Protocol* p);

};


istream& operator>>(istream& in, Protocol* p)
{
	cout << "Num TZ : "; in >> p->numTZ;
	cout << "Date   : "; in >> p->date;
	cout << "Tag    : "; in >> p->tag;
	cout << "Summa  : "; in >> p->summa;
	return in;
}

inline ostream& operator<<(ostream& out, const Protocol* p)
{
	out << p->numTZ << " " << p->date << " " << p->summa << " " << p->isPay << endl;
	return out;
}

class BasePolice
{
	BTree<String, List<Protocol*>> base;


	

public:
	void addProtocol();
	void printAll();
	void printRange(String beginNum, String endNum);
	void payment();
	void menu();
};

void BasePolice::addProtocol()
{
	Protocol* p = new Protocol;
	cin >> p;

	List<Protocol*>* list = base.getValue(p->getNumTZ());
	if (list == nullptr)
	{
		List<Protocol*> newList;
		newList.push_back(p);
		base.push_r(p->getNumTZ(), newList);
		cout << "New TZ (and Protocol) added to base" << endl;
	}
	else
	{
		list->push_back(p);
		cout << "New Protocol added to base" << endl;
	}
	system("pause");
}

void BasePolice::printAll()
{
	base.print();
}
