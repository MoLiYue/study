//1. ��֪������Ʒ��Goods���������������س�Ա�����Ķ��壬ʹ֮�ܹ�������صĹ��ܡ�
//201892419 ������
#include<iostream>
using namespace std;
class Goods
{
	int id;  		  //��Ʒ���
	char name[10];  //��Ʒ����
	double price;   //��Ʒ�۸�
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
	cout << "��Ʒ���:" << id << ", ��Ʒ���ƣ�" << name << ", ��Ʒ�۸� : " << price << "RMB";
}

//������Ʒ��Goods�����һ����Ʒ��¼��Record������ʹ����Ԫ��
//���԰�����Ʒgoods��������Ʒʵ�����ѽ��cost���Լ���Ʒ�ۿ�discount������������Ʒ����ͳһ���ۿ���Ϊ0.8����
//��������ʽ���£����������������������壬ʹ��ͨ��main()�����в��ԡ�

class Record   // ��Ʒ��¼��
{
protected:
	Goods goods;  //��Ʒ
	double cost;   //ʵ�����ѣ���ֵΪ0
	static double discount; //�ۿ��ʣ�ֵΪ0.8
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
	cout << " ���ѽ�" << cost << "RMB" << endl;
}
double Record::discount = 0.8;
int main()
{
	Goods food(1001, "Bread", 2.5);
	Goods dress(2012, "T-shirt", 129);
	Record r[3] = { food, dress };
	cout << "�ۿ��ʣ�" << Record::getCount() << endl;
	for (int i = 0; i < 3; i++)
		r[i].show();
	return 0;
}

//������Ϊ��
//�ۿ��ʣ�0.8
//��Ʒ���:1001, ��Ʒ���ƣ�Bread, ��Ʒ�۸� : 2.5RMB ���ѽ�2RMB
//	��Ʒ��� : 2012, ��Ʒ���ƣ�T - shirt, ��Ʒ�۸� : 129RMB ���ѽ�103.2RMB
//	��Ʒ��� : 0, ��Ʒ���ƣ�NULL, ��Ʒ�۸� : 0RMB ���ѽ�0RMB
