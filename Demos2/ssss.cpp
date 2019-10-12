#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
	String(const char* s)
	{
		text = new char[strlen(s) + 1];
		strcpy(text, s);
	}
	String(const String& s)
	{
		text = new char[strlen(s.text) + 1];
		strcpy(text, s.text);
	}
	~String()
	{
		delete[] text;
	}
private:
	char* text;
};

int main()
{
	String s("ABC");
	String s2(s);
}
