#pragma once
#include <iostream>

using namespace std;

class Fraction
{

	int numerator;
	int denominator;

public:
	Fraction() : Fraction(0, 1) // delegating constructor
	{
	}

	Fraction(int n, int d)
	{
		numerator = n;
		denominator = d;
	}

	void print()
	{
		cout << numerator << "/" << denominator << endl;
	}

	int getNumerator() const
	{
		return numerator;
	}

	int getDenominator() const
	{
		return denominator;
	}

	Fraction operator-()
	{
		return Fraction(-numerator, denominator);
	}


	Fraction operator+(const Fraction& f) const
	{
		Fraction result;
		result.numerator = this->numerator * f.denominator + f.numerator * denominator;
		result.denominator = denominator * f.denominator;
		return result;
	}

	Fraction operator++() // pre
	{
		this->numerator = this->numerator + this->denominator;
		return *this;
	}

	Fraction operator++(int) // post
	{
		Fraction f = *this;
		this->numerator = this->numerator + this->denominator;
		return f;
	}

	Fraction operator-(const Fraction& f)
	{
		cout << "Ha-ha-ha" << endl;
		return Fraction();

		/*Fraction result;
		result.numerator = numerator * f.denominator - f.numerator * denominator;
		result.denominator = denominator * f.denominator;
		return result;*/
		
	}

	void operator+=(const Fraction& f)
	{
		*this = *this + f;
	}

	Fraction operator+(int n) const 
	{
		return *this + Fraction(n, 1);
	}

	/*auto operator<=>(const Fraction& f)
	{
		return (float)numerator / denominator <=> (float)f.numerator / f.denominator;
	}*/

	bool operator==(const Fraction& f)
	{
		return (float)numerator / denominator == (float)f.numerator / f.denominator;
	}

	operator float()
	{
		return (float)numerator / denominator;
	}

};


Fraction operator+(int n, const Fraction& f)
{
	return f + n;
}


//Fraction operator+(const Fraction& f1, const Fraction& f2)
//{
//	int numerator = f2.getNumerator() * f1.getDenominator() + f1.getNumerator() * f2.getDenominator();
//	int denominator = f2.getDenominator() * f1.getDenominator();
//	return Fraction(numerator, denominator);
//}
