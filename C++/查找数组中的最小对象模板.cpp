#include<iostream>
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
	long showid() {
		return id;
	}
};
Student::Student()
{
	id = 0;
	name = new char[8];
	strcpy_s(name, 8, "noName");
	sex = 'U';
}

Student::Student(int i, char* n, char n1)
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
	delete[]name;
}


template<class T>
class Compare
{
protected:
	int n;
	int index;
public:
	Compare(T* a, int i) {
		n = i;
		index = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[index] > a[j])
				index = j;
		}
		cout << a[index] << endl;
	}

};
template<>
class Compare<Student>
{
protected:
	int n;
	int index;
public:
	Compare(Student* a,int i)
	{
		n = i;
		index = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[index].showid() > a[j].showid())
				index = j;
		}
		a[index].show();
	}
	
};


int main()
{
	int a[5] = { 3,2,1 };
	char b[] = "hello";
	Student s1(2005, (char*)"xu", 'F'), s2(2001, (char*)"Yu", 'M'), s3(2006, (char*)"Tian", 'F'), s[3];
	s[0] = s1; s[1] = s2; s[2] = s3;
	Compare<int> C1(a, 5);
	Compare<char> C2(b, 5);
	Compare<Student> C3(s, 3);
}