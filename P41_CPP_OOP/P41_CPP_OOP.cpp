#include <iostream>

#include "Student.h"
#include "Array.h"
#include "String.h"
#include "Time.h"
#include "Reservoir.h"

using namespace std;


void print(String a)
{
	cout << a.get() << endl;	
}


enum class Fruit
{
	APPLE,
	BANANA,
	ORANGE = 100,
	GRAPE,
	PEAR
};

enum class Color
{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	ORANGE
};

int main()
{
	//05.04.2025

	Reservoir r1(ReservoirType::SEA, "Black Sea", 10000, 20000, 1000);
	r1.print();

	Reservoir r2(r1);
	r2.print();

	Reservoir r3 = r1;
	r3.print();

	


	//String s1("Black Sea");
	//String s2("mama");
	////
	//s2 = s1 = s2 = s1; // s2.op=(s1);



	/*Fruit f = Fruit::APPLE;
	Color c = Color::RED;
	
	switch (f)
	{
	case Fruit::APPLE:
		break;
	case Fruit::BANANA:
		break;
	case Fruit::ORANGE:
		break;
	case Fruit::GRAPE:
		break;
	case Fruit::PEAR:
		break;
	default:
		break;
	}*/



	/*String s("mama");
	cout << s.get() << endl;
	print(s);
	cout << s.get() << endl;

	String s2(s);

	String s3 = s;*/




	// 01.04.2025


	//Time t1(20);
	//t1.print();

	//Time t[10];


	//String s1;
	//String s2(10);
	//const String s3("mama");

	//cout << s1.get() << endl;	
	//cout << s2.get() << "mama" << endl;	// print(s2);
	//cout << s3.get() << endl;

	////s3.set();
	//cout << s3.get() << endl;


	//cout << String::length("mama") << endl;




	/*const Array a1(10);
	a1.set();
	a1.print();
	a1.insert(100, 5);
	a1.print();	*/
	////print(10);
	//a1.print();

	

	//cout << Student::totalObjects << endl;
	//{
	//	cout << Student::getPlanet() << endl;

	//	Student s1(1, "John", 18, 5);
	//	Student s2(2, "Jane", 18, 10);
	//	cout << Student::totalObjects << endl;
	//	//cout << s1.getCount() << endl;
	//	//cout << s2.getCount() << endl;

	//	cout << s1.getPlanet() << endl;
	//	s1.setPlanet(8);

	//	cout << s2.getPlanet() << endl;
	//}

	//cout << Student::totalObjects << endl;

	//int a = 5;
	//int b(5);
	//int c { 5 };



	/*char* name;
	{
		Student s1(1, "John", 20);
		s1.print();
		name = s1.getName();
	}

	cout << name << endl;*/

	//Student s1(1, "John", 20);
	//s1.print();

	//s1.setName("John Doe");
	///*s1.id = 1;
	//s1.setAge(20);
	//s1.setName("John");*/
	//s1.print();

	//Student s2;
	//s2.print();


	system("pause");
}
