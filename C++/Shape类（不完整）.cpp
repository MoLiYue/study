//ʵ����ͼ�е�Shape��νṹ��
//ÿ����άͼ����Ӧ����ͼ������ƽ��λ�ã�Point2D����󣩡��߳���뾶�����ݳ�Ա��
//��Ա���������вι��캯��������Լ������άͼ�ε�������ܳ���
//ÿ����άͼ����Ӧ����ͼ�������ռ�λ�ã�Point3D����󣩡��߳���뾶�����ݳ�Ա��
//�����вι��캯��������Լ�������άͼ�εı����������ĳ�Ա������
//��һ��ͼ�������Ÿ���ͼ������󣬲���ѭ���ṹͳһ����������Ӧ��Ϣ��
//��άͼ������������������ݳ�Ա���ܳ����������άͼ������������������ݳ�Ա��������������

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
	Circle(double, char*, int, int);	        // ���캯��
	Circle();
	void setRadius(double r1);  		// �ð뾶
	double getRadius() const;       // ���ذ뾶
	double area() const;		    // �������
	double perimeter() const;       // �����ܳ�
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

