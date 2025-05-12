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
};


class BasePolice
{
	BTree<String, List<Protocol*>> base;

public:
	void addProtocol();
	void printAll();
	void printRange(String beginNum, String endNum);
	void payment();
};
