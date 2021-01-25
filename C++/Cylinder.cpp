/*����һ������Point���ڴ˻�������������������Square��ԲCircle�࣬
������������������Cube��Բ������Cylinder��
����������Ա�Լ���֮��Ĺ�ϵ����᲻ͬ�̳з�ʽ���ڳ�Ա���ʵ����ơ�*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

// ����
class Point
{
  public:
        Point( int a = 0, int b = 0 )
			:x(a),y(b)
		{	
			//cout<<"Point"<<endl; 
		}
		Point(const Point &a);
        int getX( ) const { return x ; }
        int getY( ) const { return y ; }
		void print()const
		{	cout << '[' << x << "," << y << "]" <<endl ;}
		double distance(const Point& a);
  protected:
        int x;
        int y;
};
Point::Point(const Point &a)
{
	x = a.x;
	y = a.y;
}
double Point::distance(const Point& a)
{
	double dx = x - a.x;
	double dy = y - a.y;
	return sqrt(dx*dx + dy * dy);
}
//��������
class Square :public Point
{
protected:
	Point &p;
	double bc;
public:
	Square(Point &a); 
	void print();
};
Square::Square(Point &a) : Point(0, 0),p(a)
{
	bc = distance(a) / sqrt(2);
}
void Square::print()
{
	Point::print();
	cout << "�߳�" << bc << endl;
}
//��������
class Cube :public Point
{
protected:
	double lc;
	Point &p;
public:
	Cube(Point &a);
	void print();
};
Cube::Cube(Point &a):Point(0,0),p(a)
{
	lc = distance(a) / sqrt(3);
}
void Cube::print()
{
	Point::print();
	cout << "�ⳤ" << lc << endl;
}
// Բ��
class Circle : public Point
{
  public:
     Circle(int x=0, int y=0, double r=1.0);	// ���캯��
     void setRadius(double);  		//�ð뾶
     double getRadius( ) const;     //���ذ뾶
     double area( ) const;		    // �������
     void print() const;
  protected:
     double radius;			// ���ݳ�Ա�뾶
     static double Pi;
    // Point center;
};
double Circle::Pi = 3.14159;
Circle::Circle(int xx, int yy, double r):Point(xx,yy)
{       cout<<"Circle"<<endl;
         radius = ( r >= 0 ? r : 0 );
}
void Circle::setRadius ( double r )
 { radius = ( r >= 0 ? r : 0 ); }
double Circle::getRadius() const { return  radius; }
double Circle::area() const{ return  Pi * radius * radius ; }
void Circle:: print() const
{
   cout << '[' << x << "," << y << "], r = " <<radius<<endl;
}
class Cylinder:protected Circle
{
public:
	Cylinder(int x, int y, double r, double h);
	Cylinder(Circle &a, double h);
	double setH(double h);
	double getH()const;
	double volumn()const;
	double area() const;

protected:
	double height;
};
Cylinder::Cylinder(int x, int y, double r, double h) :Circle(0,0,0)
{
	this->x = x;
	this->y = y;
	radius = r;
	height = h >= 0 ? h : -1;
}
Cylinder::Cylinder(Circle &a, double h) :Circle(0, 0, 0)
{
	this->x = a.getX();
	this->y = a.getY();
	radius = a.getRadius();
	height = h >= 0 ? h : -1;
}
double Cylinder::getH()const
{
	return height;
}
double Cylinder::area() const
{
	return Pi * radius * radius;
}
double Cylinder::volumn()const
{
	return Pi * radius * radius * height;
}
double Cylinder::setH(double h)
{
	height = h;
	return height;
}
int main()
{
   Point p;
   p.print();

   Circle c(1,2,3.3);
   c.print();

  //Cylinder cy(1,2,3.3,4.5);
  Cylinder cy(c,5.5);
  //cy.print();

   return 0;
}
