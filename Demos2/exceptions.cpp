#include <exception>
#include <iostream>

using namespace std;


class MuchTooBig : public exception
{
public:
	virtual const char* what() const noexcept
	{
		return "much too big";
	}
};

struct TooBig : exception
{
	virtual const char* what() const noexcept
	{
		return "too big";
	}
};

class X
{
public:
	X(int a):a(a) {}
	bool operator>(int rhs)
	{
		return a > rhs;
	}
private:
	int a;
};

int main()
{
	try
	{
		X x(70);
		if(x > 100) throw MuchTooBig();
		if(x >  50) throw TooBig();
	} catch(const exception& e) {
		cout << e.what() << endl;
	}
}

