/********************************************************************
 *
 * Handle Body
 *
 *******************************************************************/

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define WORD_LENGTH 120


#include <iostream>

using namespace std;

class String
{
public:
	String(const char*);
	String(const String&);
	String& operator=(const String& rhs);
	~String();
private:
	class Body;
	Body* pBody;
};

class String::Body
{
public:
	Body(const char* s);
	~Body();
	void increment()
	{
		count++;
	}
	void decrement()
	{
		count--;
		if (count == 0)
		{
			delete this;
		}
	}
private:
	size_t count;
	char* text;
};

String::Body::Body(const char* s)
{
	text = new char[strlen(s)+1];
	strcpy(text, s);
	count = 1;
}

String::Body::~Body()
{
	cout << "deleting " << text << endl;
	delete[] text;
}

String::String(const String& s)
{
	pBody = s.pBody;
	pBody->increment();
}
String::String(const char* s)
{
    pBody = new Body(s);
}
String& String::operator=(const String& rhs)
{
	if(this == &rhs) return *this;
	pBody->decrement();
	pBody = rhs.pBody;
	pBody->increment();
	return *this;
}

String::~String()
{
	pBody->decrement();
}

int main()
{
	String t1("XYZ");
	String t2(t1);
	String s1("ABCDEF");
	String s2(s1);
	String s3(s1);
	s2 = t2 = t1 = s2;
	cout << endl;
}
