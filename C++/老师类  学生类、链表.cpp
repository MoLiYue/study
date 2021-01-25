//(6) 设计老师类，每个老师有姓名和研究方向，还可以指导若干个研究生；名研究生有姓名，专业和学号；
//编写一个程序，创建包含三个教师的数组，用初始化列表初始化教师的信息。
//输入每个老师的指导所有研究生的信息，输出所有教师的相关信息，包括指导学生情况。
#include<iostream>
#include<cstring>
#include<stdlib.h>

//#include"标头.h"
using namespace std;

class Student
{
private:
	char* name, *major;
	long id;
	Student *s;
public:
	void set();
	Student(char* n1 = NULL, char* n2 = NULL, long idin = 201892000);
	~Student() { delete[]name; delete[]major; }
	void show();
};
class Teacher
{
private:
	char* name,*major;
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
	stu->show();
}
void Teacher::set()
{
	cout << "input teacher name" << endl;
	cin >> name;
	cout << "input teacher major" << endl;
	cin >> major;
	stu = new Student;
	stu->set();
}

Student::Student(char* n1, char* n2, long idin): s(NULL)
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
	id = idin;
}
void Student::set()
{
	char a;
	cout << "input student name" << endl;
	cin >> name;
	cout << "input student major" << endl;
	cin >> major;
	cout << "input student id" << endl;
	cin >> id;
	cout << "add another student?(y/n)" << endl;
	cin >> a;
	if (a == 'y')
	{
		s = new Student;
		s->set();
	}										//要在Student后面定义函数就行

}
void Student::show()
{
	cout << name << endl;
	cout << major << endl;
	cout << id << endl;
	s->show();
}
int main()
{
	Teacher tea[3] = {((char*)"lzx",(char*)"maths"),
						((char*)"jzx",(char*)"maths"),
						((char*)"yan",(char*)"english")};//（char*）注意把const转化变量
	tea[0].set();
	tea[0].show();
}