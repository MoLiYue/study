/*定义一个点类Point，在此基础上派生出正方型类Square和圆Circle类，
继续派生出正方体类Cube和圆柱体类Cylinder。
合理设计类成员以及类之间的关系，体会不同继承方式对于成员访问的限制。*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

// 点类
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
//正方形类
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
	cout << "边长" << bc << endl;
}
//正方体类
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
	cout << "棱长" << lc << endl;
}
// 圆类
class Circle : public Point
{
  public:
     Circle(int x=0, int y=0, double r=1.0);	// 构造函数
     void setRadius(double);  		//置半径
     double getRadius( ) const;     //返回半径
     double area( ) const;		    // 返回面积
     void print() const;
  protected:
     double radius;			// 数据成员半径
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
