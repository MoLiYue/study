//该公司主要有4类人员：经理、兼职技术人员、销售员和销售经理。要求存储这些人的编号、姓名和月工资，计算月工资并显示全部信息。
//月工资计算办法是：经理拿固定月薪8000元，兼职技术人员按每小时100元领取月薪，
//销售员按当月销售额的4%提成，销售经理既拿固定月工资也领取销售提成，固定月工资为5000元，销售提成为所管辖部门当月销售总额的5‰。
//用合理的数据结构管理所有的人员，输出他们的个人信息。



#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
	char *name;
	unsigned id;
public:
	void print();
	Person(const char* n, unsigned d);
	/*void inputName(char* n) {
		if (n)
		{
			name = new char[strlen(n)];
			strcpy_s(name, strlen(n), n);
		}
		else
		{
			name = new char[8];
			strcpy_s(name, 8, "no name");
		}
	}
	void inputID(unsigned d) {
		id = d;
	}*/
	void inputName() {
		cout << "inputName" << endl;
		cin >> name;
	}
	void inputID() {
		cout << "inputID" << endl;
		cin >> id;
	}
	~Person() {
		delete[]name;
	}
};
Person::Person(const char* n, unsigned d)
{
	if (n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	else
	{
		name = new char[8];
		strcpy_s(name, 8, "no name");
	}
	id = d;
}
void Person::print()
{
	cout << "name: " << name << endl
		<< "id: " << id << endl;
}
class Technician:public Person
{
protected:
	double salary;
	int hour;
public:
	void sal(int hour) {
		salary = hour * 100;
	}
	void workhour() {
		cout << "work hours" << endl;
		cin >> hour;
	}
	Technician(int h) :hour(h), Person("sb", 10000) {
		salary = hour * 100;
	};
};
class Manager:public Person
{
protected:
	static double salary;
public:
	void print(){
		Person::print();
		cout << "salary" << salary << endl;
	}
	Manager():Person("sb", 10000) {};
};
double salary = 8000;
class Seller:public Person
{
protected:
	double salary;
	double sales;
public:
	void sal(double sales) {
		salary = sales * 0.04;
	}
	void print() {
		Person::print();
		cout << "salary" << salary << endl;
	}
	Seller(double sales):sales(sales),Person("sb", 10000) {
		salary = sales * 0.04;
	};
};
class SalesManager:public Person
{
protected:
	double salary;
	double ALLsales;
public:
	void sal(double ALLsales) {
		salary = ALLsales * 0.005 + 5000;
	}
	void print() {
		Person::print();
		cout << "salary: " << salary << endl;
	}
	SalesManager(double ALLsales):ALLsales(ALLsales),Person("sb", 10000) {
		salary = ALLsales * 0.005 + 5000;
	};
};
int main()
{
	SalesManager sm1(10000000);
	sm1.print();
	//sm1.inputName();
	sm1.inputID();
	sm1.print();
	cout << "What a f**k!" << endl;
}