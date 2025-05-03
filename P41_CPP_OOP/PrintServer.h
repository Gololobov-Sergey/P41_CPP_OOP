#pragma once
#include<iostream>
#include <iomanip>

#include "PriorityQueue.h"
#include "String.h"
#include "Array.h"


using namespace std;


enum class DEPARTMENT
{
	GENERAL, TRANSPORT, ECONOMIST, DIRECTOR
};

ostream& operator<< (ostream& out, const DEPARTMENT& d)
{
	switch (d)
	{
	case DEPARTMENT::GENERAL:   out << "GENERAL"; break;
	case DEPARTMENT::TRANSPORT: out << "TRANSPORT"; break;
	case DEPARTMENT::ECONOMIST: out << "ECONOMIST"; break;
	case DEPARTMENT::DIRECTOR:  out << "DIRECTOR"; break;
	}
}


class TaskPrint
{
	String fileName;
	size_t time;
	DEPARTMENT department;

public:
	TaskPrint(String fName, size_t time, DEPARTMENT dept) : fileName(fName), time(time), department(dept) {	}

	DEPARTMENT getDepartment()
	{
		return department;
	}

	size_t getTime()
	{
		return time;
	}

	friend ostream& operator<<(ostream& out, const TaskPrint& tp);
};

ostream& operator<<(ostream& out, const TaskPrint& tp)
{
	out << setw(10) << left << tp.department << setw(10) << tp.fileName << " " << tp.time << endl;
	return out;
}

class PrintServer
{
	String ip;
	PriorityQueue<TaskPrint, DEPARTMENT> qPrint;
	Array<TaskPrint> stats;

	size_t totalTime = 0;

	size_t leftTime = 0;

	TaskPrint* currentTask = nullptr;

public:

	PrintServer(String ip) : ip(ip)	{ }

	void addTask(TaskPrint tp)
	{
		qPrint.enqueue(tp, tp.getDepartment());
	}

	void work()
	{
		if (qPrint.length() > 0 && currentTask == nullptr)
		{
			currentTask = new TaskPrint(qPrint.peek());
			qPrint.dequeue();
			leftTime = currentTask->getTime();
		}

		system("cls");
		cout << "PrintServer : " << ip << endl;
		cout << "-----------------------------" << endl;
		cout << endl;

		cout << "Current document : left time - " << leftTime << endl;
		if (currentTask)
		{
			cout << *currentTask << endl;
		}
	}
};



