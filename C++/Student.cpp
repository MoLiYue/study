//（4）利用日期类Date, 设计学生类Stu，私有数据成员包括学号和姓名int id;  char name[20];  和表示入学日期内嵌时间对象Date roll; 以及统计学生对象数目的静态成员number。公有成员函数实现以下功能：
//1)	定义各种构造函数，实现对成员的初始化，默认学生对象的名字是“ssdut”，默认入学日期为2013年8月28日，学号为当前学生数目number的值，每创建一个对象则number加1。若有Date d(9, 1, 2012), 则可定义学生数组
//Stu s[3] = { Stu(”S1”, 8,3,1994), Stu(”S2”, d1), Stu(“S2”) };
//三个学生的学号自动设置为分别为1, 2和3；
//2）显示学生相关信息的show(), 按清晰格式输出学生的所有信息
//3）设置学生姓名的setName(char* n)
//4)  获取number的静态成员函数 getNum()
//请给出完整的类定义，并在main（）中进行测试。

#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;
int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

class Date
{
private:
	int year, month, day;
public:
	Date() :year(0), month(0), day(0) {};
	Date(int yy, int mm, int dd) :year(yy), month(mm), day(dd) {};
	bool set(int y, int m, int d);
	void showTime();
	//int WhatDay();
	int WhichDay();
};
void Date::showTime()
{
	cout << (month < 10 ? " " : "") << month << '/';
	cout << (day < 10 ? " " : "") << day << '/';
	if (year < 10)
		cout << "   " << year << endl;
	else if (year < 100)
		cout << "  " << year << endl;
	else if (year < 1000)
		cout << " " << year << endl;
	else
		cout << year << endl;
}
int Date::WhichDay()
{
	int sum = 0, i;
	if (!(year % 4 && (!year % 100) || year % 400))
		a[1]++;
	for (i = 0; i < month - 1; i++)
	{
		sum += a[i];
	}
	return sum += day;
}
bool Date::set(int y, int m, int d)
{

	if (d<0 || d>a[m - 1])
		return false;
	else
		day = d;
	if (m < 0 || m>12)
		return false;
	else
		month = m;
	year = y;
	return true;
}

class Stu
{
private:
	int id;
	char *name;
	Date roll;
	static long number;
public:
	Stu(char *n, int month, int day, int year);
	~Stu();
	void show();
	void setName(char* n);
	static long getNum();
};
long Stu::number = 201892000;
Stu::Stu(char *n = NULL,int month = 8,int day = 28,int year = 2018):roll(year,month,day)
{
	if (n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	else
	{
		name = new char[6];
		strcpy_s(name, 6, "ssdut");
	}
	number += 1;
	id = number;
}
void Stu::show()
{
	cout << name << endl;
	cout << id << endl;
	roll.showTime();

}
void Stu::setName(char* c)
{
	name = c;
}
long Stu::getNum()
{
	cout << number;
	return number;
}
Stu::~Stu()
{
	delete[]name;
}
int main()
{
	char fuck[100] = { 0 };
	Stu stu[3];
	/*stu[1].getNum();
	cout << "input name" << endl;
	cin >> fuck;
	stu[1].setName(fuck);*/
	stu[0].show();
	stu[1].show();
	stu[2].show();
	return 0;
}
