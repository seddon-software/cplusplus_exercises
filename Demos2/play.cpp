#include <iostream>
#include <vector>
using namespace std;

namespace xyz
{
	void f()
	{
		cout << "xyz::f()" << endl;
	}
	void g()
	{
		cout << "xyz::g()" << endl;
	}
}

namespace abc
{
	void f()
	{
		cout << "abc::f()" << endl;
	}
	void h()
	{
		cout << "abc::h()" << endl;
	}
}

using namespace abc;
using namespace xyz;

int main()
{
	xyz::f();
}
