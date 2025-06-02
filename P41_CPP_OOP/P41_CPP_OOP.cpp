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
#include "BTree.h"
#include "BasePolice.h"
#include <forward_list>
#include "Relation.h"
#include "Inherit.h"
#include "Passport.h"
#include "Animal.h"
#include "Shape.h"
#include "WarOfWorld.h"
#include "Logger.h"
#include "Namespace.h"
#include "MyException.h"

using namespace std;


void print(String a)
{
	std::cout << a.get() << std::endl;
}


enum class Fruit
{
	APPLE,
	BANANA,
	ORANGE = 100,
	GRAPE,
	PEAR
};


void print(IPrintable* obj)
{
	obj->print();
}


void mult2(int& elem)
{
	elem *= 2;
}

void division(int a, int b, ILogger* log)
{
	if (b == 0)
	{
		log->logError("Division by zero!");
		return;
	}

	cout << (double)a / b << endl;
}

//using namespace Foo;
//using namespace Boo;

//namespace Moo = Foo::Doo;


double division(int a, int b)
{
	if (b == 0)
		//throw MyException(__DATE__, __TIME__, __FILE__, __LINE__, "Division by zero, b = 0") ;
		throw out_of_range("Division by zero, b = 0");
	return (double)a/b;
}


int main()
{

	int a, b;
	cin >> a >> b;
	
	try
	{
		cout << division(a,b) << endl;
	}
	catch (MyException& e)
	{
		cout << e.getError() << endl;
		e.saveError();
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "Fatal error" << endl;
	}
	
	for (size_t i = 0; i < length; i++)
	{

	}

	/*Foo::foo();
	Boo::foo();

	Foo::Doo::foo();
	Moo::foo();

	using std::cout;*/

	
	/*string pass;
	cin >> pass;
	hash<string> h;
	cout << h(pass) << endl;*/




	/*Реализовать следующую систему классов :
	Класс “Компьютер”.Поля : название, объем оперативной памяти, название
	видеокарты.
	Класс “Сервер”.Поля : количество ядер в процессоре, количество каналов
	связи с интернет, особенности(строка).
	Класс “Персональный компьютер” – наследуется от класса «Компьютер».
	Поля : наличие звука, название звуковой карты.Тип мыши(мышь / трекбол).
	Класс “Ноутбук” – наследуется от класса «Компьютер».Поля : диагональ
	дисплея, время жизни батареи, вес.
	Класс “Переносной сервер” – наследуется от “Сервер” и “Ноутбук”.Поля :
	наличие доступа в интернет, название сервера, название операционной системы.
	Используются : виртуальные функции вывода данных, параметризованные
	конструкторы, деструктор.*/




	/*Router r(123);
	cout << r.LAN::getID() << endl;
	cout << r.WiFi::getID() << endl;*/

	/*Animal* a = new Cat("Tom", 3);
	Cat* c = dynamic_cast<Cat*>(a);
	if(c)
		cout << c->getMouse() << endl;*/
	


	//int a = 9, b = 0;

	//ConsoleLogger* clog = new ConsoleLogger();

	//FileLogger* flog = new FileLogger("log.txt");

	//division(a, b, new FileLogger("log.txt"));


	/*Light* sw = new Swordsman(50, 90);
	cout << sw << endl;*/
	

	/*WarOfWorld war(5);
	war.game();*/



	//24.05.2025

	/*Shape* c = new Circle(3.5, 5.7, 20);
	c->info();
	cout << "Area = " << c->area() << endl;*/

	/*{
		Animal* a = new Cat("Tom", 3);
		delete a;
	}*/
	/*cout << c.getType() << endl;
	c.info();
	cout << c.voice() << endl;

	Animal& rc = c;
	cout << rc.getType() << endl;
	rc.info();
	cout << rc.voice() << endl;*/

	//Animal* pa = new Animal("xxxx", 3);

	//Animal* pc = new Cat("Tom", 3);
	/*cout << pc->getType() << endl;
	pc->info();
	cout << pc->voice() << endl;*/

	//cout << endl;

	//Animal* pd = new Dog("Spike", 5);
	/*cout << pd->getType() << endl;
	pd->info();
	cout << pd->voice() << endl;*/

	/*Animal* pp = new Parrot("Kesha", 1);

	Animal* sc = new SiamCat("Murka", 4);

	Animal* an[] = { pc, pd, pp, sc };


	for (size_t i = 0; i < 4; i++)
	{
		cout << an[i]->getType() << endl;
		an[i]->info();
		cout << an[i]->voice() << endl;
		cout << endl;
	}*/


	/*Cat c1("c", 2);
	Dog d1("d", 3);
	Animal an1[] = { c1, d1 };
	for (size_t i = 0; i < 2; i++)
	{
		cout << an1[i].getType() << endl;
		an1[i].info();
		cout << an1[i].voice() << endl;
		cout << endl;
	}*/

	//17.05.2025

	/*Human h("Vasya", 30);
	h.info();
	

	FootbalPlayer fp("Ronaldo", 38, 7);

	fp.info();*/
	

	/*UkrainianPassport passport1("Ivan", "Ivan", "Ivan", "01.09.1839", "AZ7777EU", "19.05.2025");

	passport1.info();

	UkrainianForeignPassport passport2("Amerika", "Comes", "01.09.2013", "US$$$$US", "19.05.2025");

	passport2.info();

	passport2.addVisa();

	passport2.showVisa();*/


	/*A a;
	B b;*/
	



	/*{
		Car1 car1;
	}*/



	/*Engine1* engine = new Engine1;
	Car2 car2(engine);
	car2.info();

	STO sto;
	sto.setEngineToStend(car2.getEngine());
	sto.upPower(60);
	car2.info();

	car2.setEngine(sto.getEngine());
	car2.info();*/





	/*Engine1* engine2 = new Engine1;
	car2.getEngine(engine2);*/



	//12.05.2025

	/*BasePolice base;
	base.addProtocol();
	base.addProtocol();
	base.addProtocol();
	base.printAll();*/



	/*BTree<int, int> bt;
	bt.push_r(20, 20);
	bt.push_r(10, 10);
	bt.push_r(40, 40);
	bt.push_r(5, 5);
	bt.push_r(1, 1);
	bt.push_r(30, 30);
	bt.print();*/



	//10.05.2025

	//List<int> l = { 1,2,3,4,5 };
	/*l.push_back(99);
	l.push_front(88);
	l.print();
	l.insert(77, 1);
	l.print();
	l.insert(66, 4);
	l.print();
	l.clear();
	l.print();*/

	//l.remove(3);
	//l.print();




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


	/*BaseQueue<int, int> pq;
	pq.enqueue(10);
	pq.enqueue(20, 1);
	pq.enqueue(30, 1);
	pq.enqueue(40, 5);
	pq.enqueue(50, 4);
	pq.enqueue(60, 4);

	pq.print();*/


	//PriorityQueue<int, int> q; // = { 1,3,5,8,9 };
	//q.enqueue(30, 3);
	//q.enqueue(10, 1);
	//q.enqueue(20, 2);
	//q.enqueue(40, 4);
	//q.print();


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
