#pragma once
#include<iostream>
#include<fstream>

using namespace std;


class ILogger
{
public:
	virtual ~ILogger() {}

	virtual void logError(string error) = 0;
};

class ConsoleLogger : public ILogger
{
public:

	virtual void logError(string error) override
	{
		cout << error << endl;
	}
};


class FileLogger : public ILogger
{
	string path;

public:

	FileLogger(string path) : path(path) {}

	virtual void logError(string error) override
	{
		ofstream out(path, ios::app);
		out << error << endl;
		out.close();
	}
};
