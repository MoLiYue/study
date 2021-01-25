#include<iostream>
#include<cstring>
#include"БъЭЗ.h"
using namespace std;

class Teacher
{
private:
	char* name, *major;
	Student* stu;
public:
	void show();
	Teacher(char* n1 = NULL, char*n2 = NULL);
	~Teacher() { delete[]name; delete[]major; }
	void set();
};
Teacher::Teacher(char* n1, char*n2)
{
	if (n1)
	{
		name = new char[strlen(n1) + 1];
		strcpy_s(name, strlen(n1) + 1, n1);
	}
	else
	{
		name = new char[8];
		strcpy_s(name, 8, "no name");
	}
	if (n2)
	{
		major = new char[strlen(n2) + 1];
		strcpy_s(major, strlen(n2) + 1, n2);
	}
	else
	{
		major = new char[9];
		strcpy_s(major, 9, "no major");
	}

}
void Teacher::show()
{
	cout << name << endl;
	cout << major << endl;

}
void Teacher::set()
{
	stu = new Student;
	stu->set();
}