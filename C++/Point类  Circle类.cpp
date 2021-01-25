//��5�����õ���Point������Բ��Circle��˽�����ݳ�Ա����Բ��Point center�Ͱ뾶double radium; �;�̬��ԱPi = 3.14159; ���г�Ա����ʵ�����¹��ܣ�
//1�����ظ��ֹ��캯�����������Բ��������ʽ��洢�������С�
//Circle cc[3] = { Circle(1,2,3.3), Circle(3) };
//2�����峣��Ա����show()�����Ϣ������Բ��Ϣ��
//���� cc[0] : ��1, 2����r = 3.3.cc[1] : ��0, 0����r = 3.  cc[2] : (0, 0), r = 1
//3�����峣��Ա����area()����Բ�����
//4) ���Դ�жϵ���Բ�Ĺ�ϵjudge()�� ��p��Բ�ڻ�Բ�Ϸ���true�����򷵻�false��
//˼������Ԫ�������ǳ�Ա�������ܷ������������distance()����


#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    Point(int x = 0 ,int y = 0 ):x(x),y(y){}
	void print()const
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
   double distance(const Point& a);
private:
    int x,y;
};

double Point::distance( const Point& a )
{
    double dx= x-a.x;
    double dy= y-a.y;
    return sqrt(dx*dx+dy*dy);
}

class Circle
{
public:
	Circle(double rr = 1, int xx = 0, int yy = 0);
	void print()const ;
	double area();
	int judge( const Point& p);

private:
    int x, y;         //Point center;
	double radius;
	Point center;
	const double Pi;
};
Circle::Circle(double rr, int xx, int yy) :Pi(3.1415), center(xx, yy)
{
	x = xx;
	y = yy;
	radius = rr;
}
void Circle::print()const
{
	cout << radius << endl;
	center.print();

}
double Circle::area()
{
	double area;
	area = Pi * radius*radius;
	return area;
}
int Circle::judge(const Point& p)
{
	double dis;
	dis = center.distance(p);
	if (dis < radius)
		return true;
	else
		return false;
}

int main( )
{
	Point p(2,3);

 	Circle c[3];
    c[0].print();
	cout<< c[0].judge(p)<<endl;

    return 0;
}
