#pragma once

#include<iostream>
#include<fstream>
#include <string>

using namespace std;


class MyException
{
	string date;
	string time;
	string file;
	int line;
	string message;

public:
	MyException(string date, string time, string file, int line, string message) : 
		date(date), time(time), file(file), line(line), message(message)
	{

	}

	string getError()
	{
		return date + " | " + time + " | " + file + " | " + to_string(line) + " | " + message;
	}

	void saveError()
	{
		ofstream out("log.txt", ios::app);
		out << this->getError() << endl;
		out.close();
	}

};