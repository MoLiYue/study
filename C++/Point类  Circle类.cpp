//（5）利用点类Point，定义圆类Circle，私有数据成员包括圆心Point center和半径double radium; 和静态成员Pi = 3.14159; 公有成员函数实现以下功能：
//1）重载各种构造函数，允许将多个圆按如下形式其存储在数组中。
//Circle cc[3] = { Circle(1,2,3.3), Circle(3) };
//2）定义常成员函数show()输出信息，例如圆信息，
//例如 cc[0] : （1, 2），r = 3.3.cc[1] : （0, 0），r = 3.  cc[2] : (0, 0), r = 1
//3）定义常成员函数area()计算圆的面积
//4) 设计源判断点与圆的关系judge()， 若p在圆内或圆上返回true，否则返回false。
//思考是友元函数还是成员函数？能否利用亮点距离distance()函数


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
