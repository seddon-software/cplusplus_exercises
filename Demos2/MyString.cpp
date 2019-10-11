#include <cstring>
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* s = "")
	{
		pBody = new char[strlen(s) + 1];
		strcpy(pBody, s);
	}
	String(const String& s)
	{
		pBody = new char[strlen(s.pBody) + 1];
		strcpy(pBody, s.pBody);
	}
	~String()
	{
		delete[] pBody;
	}
	String& operator=(const String& rhs)
	{
		if(this == &rhs) return *this;
		delete[] pBody;
		pBody = new char[strlen(rhs.pBody) + 1];
		strcpy(pBody, rhs.pBody);
		return *this;
	}
	friend ostream& operator<<(ostream& os, const String& s)
	{
		return os << s.pBody;
	}
private:
	char* pBody;
};

void f(const String& s)
{

}

void f(String& s)
{

}
void g(String s)
{

}
void g(const String* ps)
{

}
void g(String* ps)
{

}



int main()
{
	String s("abcdef");
	cout << s << endl;
	String s2(s);
	cout << s2 << endl;
	String s3;
	const String cs("xyz");
	f(s);
	f(cs);
	s3 = cs;
	g(s3);
	g(&s);
	g(&cs);
}
