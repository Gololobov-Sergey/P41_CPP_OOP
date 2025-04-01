#pragma once
#include <iostream>

using namespace std;


class Time
{
	int hour;
	int minute;
	int second;

public:
	Time() : Time(0) {}

	Time(int s) : Time(0, s) {}

	Time(int m, int s) : Time(0, m, s) {}

	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}


	void setHour(int h)
	{
		if (h < 0 || h > 23)
			return;
		hour = h;
	}
	void setMinute(int m)
	{
		if (m < 0 || m > 59)
			return;
		minute = m;
	}
	void setSecond(int s)
	{
		if (s < 0 || s > 59)
			return;
		second = s;
	}
	int getHour() const
	{
		return hour;
	}
	int getMinute() const
	{
		return minute;
	}
	int getSecond() const
	{
		return second;
	}
	void print() const
	{
		if (hour < 10)
			cout << "0";
		cout << hour << ":";
		if (minute < 10)
			cout << "0";
		cout << minute << ":";
		if (second < 10)
			cout << "0";
		cout << second << endl;
	}
};
