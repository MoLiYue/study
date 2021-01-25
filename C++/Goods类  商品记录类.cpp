//1. 已知如下商品类Goods的声明，请给出相关成员函数的定义，使之能够满足相关的功能。
//201892419 何易霖
#include<iostream>
using namespace std;
class Goods
{
	int id;  		  //商品编号
	char name[10];  //商品名称
	double price;   //商品价格
public:
	Goods(int i,const char* n, double d);
	//void setPrice(double a);
	double getPrice()const;
	//const char* getName();
	void show() const;
	Goods(Goods& a);
};
double Goods::getPrice()const
{
	return price;
}
Goods::Goods(Goods& a)
{
	id = a.id;
	strcpy_s(name, 10, a.name);
	strcpy_s(name, 10, "no name");
	price = a.price;
}
Goods::Goods(int i = 0,const char* n = "NULL", double d = 0)
{
	id = i;
	if (n)
	{
		strcpy_s(name, 10, n);
	}
	else
	{
		strcpy_s(name, 10, "no name");
	}
	price = d;
}
void Goods::show() const
{
	cout << "商品编号:" << id << ", 商品名称：" << name << ", 商品价格 : " << price << "RMB";
}

//利用商品类Goods，设计一个商品记录类Record，不得使用友元！
//属性包括商品goods，购买商品实际消费金额cost，以及商品折扣discount（假设所有商品设置统一的折扣率为0.8），
//类声明形式如下，请给出这两个类的完整定义，使其通过main()函数中测试。

class Record   // 商品记录类
{
protected:
	Goods goods;  //商品
	double cost;   //实际消费，初值为0
	static double discount; //折扣率，值为0.8
public:
	void show();
	static double getCount();
	Record(Goods& a) :goods(a) {};
	Record() {};
	Record(Record& a);
};
Record::Record(Record& a)
{

}
double Record::getCount()
{
	return discount;
}
void Record::show()
{
	double i;
	goods.show();
	i = goods.getPrice();
	cost = i * discount;
	cout << " 消费金额：" << cost << "RMB" << endl;
}
double Record::discount = 0.8;
int main()
{
	Goods food(1001, "Bread", 2.5);
	Goods dress(2012, "T-shirt", 129);
	Record r[3] = { food, dress };
	cout << "折扣率：" << Record::getCount() << endl;
	for (int i = 0; i < 3; i++)
		r[i].show();
	return 0;
}

//输出结果为：
//折扣率：0.8
//商品编号:1001, 商品名称：Bread, 商品价格 : 2.5RMB 消费金额：2RMB
//	商品编号 : 2012, 商品名称：T - shirt, 商品价格 : 129RMB 消费金额：103.2RMB
//	商品编号 : 0, 商品名称：NULL, 商品价格 : 0RMB 消费金额：0RMB
