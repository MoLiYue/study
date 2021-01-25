//实现下图中的Shape层次结构。
//每个二维图形类应包括图形名、平面位置（Point2D点对象）、边长或半径等数据成员，
//成员函数包括有参构造函数、输出以及计算二维图形的面积和周长。
//每个三维图形类应包括图形名、空间位置（Point3D点对象）、边长或半径等数据成员，
//包含有参构造函数、输出以及计算三维图形的表面积和体积的成员函数。
//用一个图形数组存放各种图形类对象，并用循环结构统一输出对象得相应信息，
//二维图形输出类名、各自数据成员、周长和面积，三维图形输出类名、各自数据成员、表面积及体积。

#include<iostream>
#include<cstring>

using namespace std;

class Shape
{
protected:
	char* name;
public:
	Shape(char*n);
};
class Point2D
{
protected:
	int x, y;
public:
	void print() {
		cout << '[' << x << "," << y << ']' << endl;
	}

	Point2D(int, int);
};
class TwoDShape: public Shape
{
public:
	TwoDShape() :Shape((char*)"TwoDShape") {};
	void show();
};
class Square : public TwoDShape, virtual public Shape, public Point2D
{
protected:
	double side;
public:
	Square();
	Square(double, char*, int, int);
	void setSide(double);
	double getArea();
	void show();
};
class Circle : public TwoDShape, virtual public Shape, public Point2D
{
public:
	Circle(double, char*, int, int);	        // 构造函数
	Circle();
	void setRadius(double r1);  		// 置半径
	double getRadius() const;       // 返回半径
	double area() const;		    // 返回面积
	double perimeter() const;       // 返回周长
	void print() const;
protected:
	double r;
	static double Pi;
};
class Point3D
{
protected:
	int x;
	int y;
	int z;
public:
	void print() {
		cout << '[' << x << "," << y << "," << z << ']' << endl;
	}
};
class ThreeDShape :public Shape
{
public:
	ThreeDShape() :Shape((char*)"ThreeDShape") {};
	void show();
};
void ThreeDShape::show()
{
	cout << "this is " << name << endl;
}
Point2D::Point2D(int xx,int yy):x(xx),y(yy){}
void TwoDShape::show()
{
	cout << "this is " << name << endl;
}
Square::Square() :side(1), Shape((char*)"Square"), Point2D(0,0){}
Square::Square(double s,char* n, int xx, int yy):side(s),Shape(n),Point2D(xx,yy){}
Shape::Shape(char*n)
{
	if (n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1,n);
	}
	else
	{
		name = new char[8];
		strcpy_s(name, 8, "no name");
	}
}
double Circle::Pi = 3.14159;
double Circle::perimeter() const
{
	return Pi * 2 * r;
}
Circle::Circle(double r1, char* n, int xx, int yy):r(r1), Shape(n), Point2D(xx, yy)
{
	cout << "Circle" << endl;
	r = (r1 >= 0 ? r1 : 0);
}
void Circle::setRadius(double r1)
{
	r = (r1 >= 0 ? r1 : 0);
}
double Circle::getRadius() const { return  r; }
double Circle::area() const { return  Pi * r * r; }
void Circle::print() const
{
}

