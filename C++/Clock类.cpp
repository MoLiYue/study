#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;
class time1
{
private:
	int hour;
	int minute;
	int second;
	int t,t1;
public:
	void setTime();
	void showTime();
	void timepass();
	void rule();
};
void time1::setTime()
{
	cout << "input hour minute second"<<endl;
	cin >> hour >> minute >> second;
}
void time1::showTime()
{
	cout <<( hour < 10 ? "0" : "" )<< hour<< ":";
	cout << (minute < 10 ? "0" : "") << minute<< ":";
	cout << (second < 10 ? "0" : "") << second<< endl;
}
void time1::timepass()
{
	t1 = time(0);
	while (1)
	{
		t = time(0);
		if (t != t1)
		{
			second++;
			time1::rule();
			t1 = t;
			system("cls");
			time1::showTime();
		}
	}

}
void time1::rule()
{
	if (second >= 60)
	{
		second = 0;
		minute++;
		if (minute > 59)
		{
			minute = 0;
			hour++;
			if (hour > 23)
			{
				hour = 0;

			}
		}
	}
}
int main()
{
	time1 t1;
	t1.setTime();
	t1.timepass();

}