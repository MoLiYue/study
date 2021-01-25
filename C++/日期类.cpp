#include<iostream>
using namespace std;

int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
class Date
{
private:
	int year,month,day;
public:
	Date():year(0),month(0),day(0){};
	Date(int yy,int mm,int dd):year(yy),month(mm),day(dd){};
	bool set(int y, int m, int d);
	void showTime();
	//int WhatDay();
	int WhichDay();
};
void Date::showTime()
{
	cout<<(month<10?" ":"")<<month<<'/';
	cout<<(day<10?" ":"")<<day<<'/';
	if(year<10)
		cout<<"   "<<year<<endl;
	else if(year<100)
		cout<<"  "<<year<<endl;
	else if(year<1000)
		cout<<" "<<year<<endl;
	else
		cout<<year<<endl;
}
int Date::WhichDay()
{
	int sum = 0,i;
	if(!(year%4&&(!year%100)||year%400))
		a[1]++;
	for(i = 0;i<month-1;i++)
	{
		sum += a[i];
	}
	return sum += day;
}
bool Date::set (int y, int m, int d)
{
	
	if(d<0||d>a[m-1])
		return false;
	else
		day = d;
	if(m<0||m>12)
		return false;
	else
		month = m;
	year = y;
	return true;
}
	
int main()
{
	Date d1;
	int y,m,d,sum;
	cout<<"input year month day"<<endl;
	cin>>y>>m>>d;
	d1.set(y,m,d);
	d1.showTime();
	sum = d1.WhichDay();
	cout<<sum;
}