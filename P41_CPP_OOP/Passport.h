#pragma once
#include<iostream>
#include"String.h"
#include"List.h"
using namespace std;

struct visa
{
	String country;
	String dateOfIssue;

	friend ostream& operator<< (ostream& out, const visa& obj)
	{
		out << obj.country << " ";
		out << obj.dateOfIssue << "\n";
		return out;
	}
};

class Passport
{
protected:
	String name;
	String surname;
	String birthday;
	String serialId;
	String dateOfIssue;
public:
	Passport();
	Passport(String name, String surname, String birthday, String serialId, String dateOfIssue) : name(name), surname(surname), birthday(birthday), serialId(serialId), dateOfIssue(dateOfIssue) {};
	~Passport();
	void info() const;
};

inline Passport::Passport()
{
}

inline Passport::~Passport()
{
}

void Passport::info() const
{
	cout << "Info:\n";
	cout << "Name         : " << name << "\n";
	cout << "Surname      : " << surname << "\n";
	cout << "Birthday     : " << birthday << "\n";
	cout << "Serial id     : " << serialId << "\n";
	cout << "Date of issue: " << dateOfIssue << "\n";
}

class UkrainianPassport : public Passport
{
private:
	String patronymic;

public:

	UkrainianPassport(String name, String surname, String patronymic, String birthday, String serialId, String dateOfIssue) : patronymic(patronymic), Passport(name, surname, birthday, serialId, dateOfIssue)
	{

	}
	~UkrainianPassport() {}
	void info() const
	{
		cout << "Info:\n";
		cout << "Name         : " << name << "\n";
		cout << "Surname      : " << surname << "\n";
		cout << "Patronymic   : " << patronymic << "\n";
		cout << "Birthday     : " << birthday << "\n";
		cout << "Serial id    : " << serialId << "\n";
		cout << "Date of issue: " << dateOfIssue << "\n";

	}
};

class UkrainianForeignPassport : public Passport
{
private:
	List<visa> visaList;
public:

	UkrainianForeignPassport(String name, String surname, String birthday, String serialId, String dateOfIssue) : Passport(name, surname, birthday, serialId, dateOfIssue)
	{

	}
	~UkrainianForeignPassport() {};
	void info() const
	{
		cout << "Info:\n";
		cout << "Name         : " << name << "\n";
		cout << "Surname      : " << surname << "\n";
		cout << "Birthday     : " << birthday << "\n";
		cout << "Serial id    : " << serialId << "\n";
		cout << "Date of issue: " << dateOfIssue << "\n";

	}
	void addVisa(visa visa)
	{
		visaList.push_front(visa);
	}
	void addVisa()
	{
		visa temp;
		cout << "Enter country: ";
		cin >> temp.country;
		cout << "Enter date of issue: ";
		cin >> temp.dateOfIssue;
		addVisa(temp);
	}
	void showVisa()
	{
		visaList.print();
	}
};
