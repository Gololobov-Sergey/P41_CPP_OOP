#include <iostream>

#include "Student.h"

using namespace std;

int main()
{
	Student s1(1, "John", 20);
	s1.print();

	s1.setName("John Doe");
	/*s1.id = 1;
	s1.setAge(20);
	s1.setName("John");*/
	s1.print();

	Student s2;
	s2.print();


	system("pause");
}
