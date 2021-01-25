#include <iostream>
#include <cstring>
using namespace std;
class myString
{
public:
	myString(const char* pn);
	myString();
	myString(myString& other);
	~myString();
	void set(const char *pn);
	void print();
	int getLen();
	bool toUpper();
private:
	char* pStr;
	int size;
};

myString::myString(const char* pn )
{
	if (pn)
	{
		pStr = new char[strlen(pn) + 1];
		strcpy(pStr, pn);
	}
	else
	{
		pStr = new char[10];
		strcpy(pStr, "No string");
	}
}

myString::myString()
{
	pStr = new char[10];
	strcpy(pStr, "No string");
}

myString::myString(myString & other)
{
	size = other.size;
	if (other.pStr)
	{
		pStr = new char[strlen(other.pStr) + 1];
		strcpy(pStr, other.pStr);
	}
	else
	{
		pStr = new char[10];
		strcpy(pStr, "No string");
	}
}

myString::~myString()
{
	delete[] pStr;
}

void myString::set(const char * pn)
{
	delete[] pStr;
	if (pn)
	{
		pStr = new char[strlen(pn) + 1];
		strcpy(pStr, pn);
	}
	else
	{
		pStr = new char[10];
		strcpy(pStr, "No string");
	}
}

void myString::print()
{
	cout << pStr << endl;
}

int myString::getLen()
{
	return strlen(pStr);
}

bool myString::toUpper()
{
	if (pStr)
		return false;
	else
	{
		for (int i = 0; i < getLen() + 1; i++)
			if (isupper(pStr[i]))
				pStr[i] += 32;
		return true;
	}
}

void main()
{
	myString s0, s1("hello");
	s0.print();
	s0.set("world");
	s0.print();
	cout << s1.getLen() << endl;
	myString s2 = s1;
	s2.print();
}