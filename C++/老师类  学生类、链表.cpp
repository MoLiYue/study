//(6) �����ʦ�࣬ÿ����ʦ���������о����򣬻�����ָ�����ɸ��о��������о�����������רҵ��ѧ�ţ�
//��дһ�����򣬴�������������ʦ�����飬�ó�ʼ���б��ʼ����ʦ����Ϣ��
//����ÿ����ʦ��ָ�������о�������Ϣ��������н�ʦ�������Ϣ������ָ��ѧ�������
#include<iostream>
#include<cstring>
#include<stdlib.h>

//#include"��ͷ.h"
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
	}										//Ҫ��Student���涨�庯������

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
						((char*)"yan",(char*)"english")};//��char*��ע���constת������
	tea[0].set();
	tea[0].show();
}