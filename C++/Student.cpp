//��4������������Date, ���ѧ����Stu��˽�����ݳ�Ա����ѧ�ź�����int id;  char name[20];  �ͱ�ʾ��ѧ������Ƕʱ�����Date roll; �Լ�ͳ��ѧ��������Ŀ�ľ�̬��Աnumber�����г�Ա����ʵ�����¹��ܣ�
//1)	������ֹ��캯����ʵ�ֶԳ�Ա�ĳ�ʼ����Ĭ��ѧ������������ǡ�ssdut����Ĭ����ѧ����Ϊ2013��8��28�գ�ѧ��Ϊ��ǰѧ����Ŀnumber��ֵ��ÿ����һ��������number��1������Date d(9, 1, 2012), ��ɶ���ѧ������
//Stu s[3] = { Stu(��S1��, 8,3,1994), Stu(��S2��, d1), Stu(��S2��) };
//����ѧ����ѧ���Զ�����Ϊ�ֱ�Ϊ1, 2��3��
//2����ʾѧ�������Ϣ��show(), ��������ʽ���ѧ����������Ϣ
//3������ѧ��������setName(char* n)
//4)  ��ȡnumber�ľ�̬��Ա���� getNum()
//������������ඨ�壬����main�����н��в��ԡ�

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
