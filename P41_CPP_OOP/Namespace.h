#pragma once

#pragma once
#include<iostream>

using namespace std;

namespace Foo
{
	void foo()
	{
		cout << "Foo->Foo" << endl;
	}

	void foo1()
	{
		cout << "Foo->Foo1" << endl;
	}


	namespace Doo
	{
		void foo()
		{
			cout << "Foo->Doo->foo" << endl;
		}
	}

}

namespace Boo
{
	void foo()
	{
		cout << "Boo->Foo" << endl;
	}
}