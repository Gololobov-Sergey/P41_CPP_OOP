#include <iostream>
#include <Windows.h>

#include "Student.h"
#include "Array.h"
#include "String.h"
#include "Time.h"
#include "Reservoir.h"
#include "Fraction.h"
#include "var.h"

#include "Stack.h"
#include "Calc.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "PrintServer.h"
#include "ForwardList.h"
#include "List.h"
#include <forward_list>

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

void mult2(int& elem)
{
	elem *= 2;
}

int main()
{
	//10.05.2025

	List<int> l = { 1,2,3,4,5 };
	/*l.push_back(99);
	l.push_front(88);
	l.print();
	l.insert(77, 1);
	l.print();
	l.insert(66, 4);
	l.print();
	l.clear();
	l.print();*/

	l.remove(3);
	l.print();




	//05.05.2025

	//ForwardList<int> fl = { 14,12,34, 1, 4 };
	//fl.print();
	/*fl.push_front(99);
	fl.push_back(88);
	fl.print();
	fl.insert(77, 3);
	fl.print();
	fl.clear();
	fl.print();*/
	//fl.remove(1);
	//fl.sort();

	/*for (size_t i = 0; i < fl.length(); i++)
	{
		fl[i] *= 2;
	}*/

	//fl.for_each(mult2);
	//fl.for_each([](int& a){ a *= 2; });

	//fl.print();


	//03.05.2025

	
	/*PriorityQueue<int, int> pq;
	pq.enqueue(10, 3);
	pq.enqueue(20, 1);
	pq.enqueue(30, 1);
	pq.enqueue(40, 5);
	pq.enqueue(50, 4);
	pq.enqueue(60, 4);

	pq.print();*/


	/*Queue<int> q = { 1,3,5,8,9 };
	q.print();
	q.ring();
	q.print();*/
		
		
	/*Calc c("12-2*2*2+2");
	cout << c.getResult() << endl;*/

	/*Stack<int, 10> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.print();
	Stack<int, 10> st2(st);
	st2.print();*/



	/*String st("mama");
	cout << st << endl;
	cin >> st;
	cout << st << endl;*/

	/*Array<char> a(10);
	a.set('A', 'X');
	a.print();*/


	/*Array<String> st;
	st.add("mama");
	st.add("papa");
	st.add("baba");
	st.print();


	Array<int> a(10);
	a.set();
	a.print();

	Array<double> b(10);
	b.set();
	b.print();*/


	//12.04.2025


	/*var a = 10;
	var b = "mama"; 
	var c = 3.14;

	a.print();
	b.print();
	c.print();

	a = b;
	a.print();

	auto d = 5;*/

	/*Array a(10);
	a.set();
	a.print();

	a[5] = 999;
	
	cout << a[3] << endl;
	cout << a["one"] << endl;
	a.print();

	a(10);

	int s = a;

	cout << ((String)a).get() << endl;


	String st("mama");
	st("papa");*/

	//Fraction f1(1, 2);
	//Fraction f2(1, 4);
	//Fraction f3 = f1 + 10;
	//f3.print();
	//Fraction f4 = 10 + f1;
	//f4.print();


	/*if (f1 < f2)
	{
		cout << true << endl;
	}
	else
	{
		cout << false << endl;
	}

	float s = f1;*/

	//"mama" * 3; // mamamamamama

	//f1 = f2;
	//f1.print();

	//f1++.print(); 
	//++f1 + f2;
	//f1.print();

	//f1 += f2; // f1 = f1 + f2

	//Fraction f3 = f1.add(f2);
	//Fraction f3 = f1 + f2; // f1.operator+(f2);
	//f3.print();
	//Fraction f4 = f1 - f2;
	//f4.print();


	//// *, ->, ., :: , sizeof(), ?:
	// 
	//// - , + , ++ , -- 
	//// +, -, *, /, =, %, += , -=, *= , /=, %=, 
	//// ! 
	//// < > <= >= != == , &&, || 
	// 
	// 


	//Time t1(0, 0, 30);
	//Time t2(0, 0, 50);
	//Time t3 = t1 + t2;
	//Time t4 = t1 + 10;
	//Time t5 = 100 + t1;
	//Time t6 = t1 - t2;
	//t1 += t2;
	//t1 -= t2;
	//t1 <=> t2;
	//int s = t1;
	//t1.print();
	//t1++;
	//++t1;
	//t1--;
	//--t1;

	//// TODO
	//String s1("mama");
	//String s2("papa");
	//s1 + s2;
	//s1 * 3;
	//3 * s1;
	//s1 <=> s2;
	//s1 += s2;



	
	//int a;
	//a++;
	//++a;

	//05.04.2025

	/*Reservoir r1(ReservoirType::SEA, "Black Sea", 10000, 20000, 1000);
	r1.print();

	Reservoir r2(r1);
	r2.print();

	Reservoir r3 = r1;
	r3.print();*/

	


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
