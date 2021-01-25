#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

class Student
{
protected:
	long id;
	char* name;
	char sex;
public:
	Student(int, char* n, char);
	Student();
	virtual ~Student();
	virtual void show();
	void setName(char* n);
};
Student::Student()
{
	id = 0;
	name = new char[8];
	strcpy_s(name, 8, "noName");
	sex = 'U';
}

Student::Student(int i,char* n,char n1)
{
	id = i;
	if (n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	else
	{
		name = new char[8];
		strcpy_s(name, 8, "noName");
	}
	if (n1)
	{
		sex = n1;
	}
	else
	{
		sex = 'U';
	}
}
void Student::show()
{
	cout << name << endl;
	cout << id << endl;
	cout << sex << endl;

}
void Student::setName(char* c)
{
	name = c;
}

Student::~Student()
{
	
	cout << "destructing Student" << name << endl;
	delete[]name;
}

class CollegeStudent :public Student
{
protected:
	char* major;
public:
	void show();
	CollegeStudent(int, char*, char, char*);
	CollegeStudent();
	~CollegeStudent();
};

CollegeStudent::CollegeStudent(int i, char* n, char s, char* m):Student(i,n,s)
{
	if (m)
	{
		major = new char[strlen(m) + 1];
		strcpy_s(major, strlen(m) + 1, m);
	}
	else
	{
		major = new char[8];
		strcpy_s(major, 8, "unknown");
	}
}
CollegeStudent::CollegeStudent():Student()
{
	major = new char[8];
	strcpy_s(major, 8, "unknown");
}
void CollegeStudent::show()
{
	cout << name << endl;
	cout << id << endl;
	cout << sex << endl;
	cout << "major = " << major << endl;
}
CollegeStudent::~CollegeStudent()
{
	cout << "destructing CollegeStudent :" << name << endl;
	delete[]major;
}

class GraduateStudent :public CollegeStudent
{
private:
	string tutor;
public:
	void show();
	GraduateStudent(int, char*,char,char*,string);
	~GraduateStudent() {
		cout << "destructing GraduateStudent:" << name << endl;
	}
};

GraduateStudent::GraduateStudent(int i, char* n, char s, char* m, string a):CollegeStudent(i,n,s,m)
{
	tutor = a;
}
void GraduateStudent::show()
{
	cout << name << endl;
	cout << id << endl;
	cout << sex << endl;
	cout << "major = " << major << endl;
	cout << tutor << endl;
}
int main()
{
	Student* pointer[5] = { new Student , new Student(1,(char*)"xu",(char)'F'),
			   new CollegeStudent, new CollegeStudent(2,(char*)"Yu",(char)'M',(char*)"Software"),
			  new GraduateStudent(3,(char*)"Ma",(char)'M',(char*)"networks",(string)"Tian") };
	for (int i = 0; i < 5; i++)
	{
		pointer[i]->show();
		delete pointer[i];
		cout << "~~~~~~~~~~~~~~~" << endl;
	}

}