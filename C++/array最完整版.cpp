#include<iostream>

using namespace std;
//3 定义小数数组类MyArray，按照如下要求实现相应功能。注意空间的开辟与释放。
//201892419 何易霖
class MyArray
{
private:
	double *data;          //数组首地址
	unsigned length;       // 数组元素个数
public:
	MyArray(unsigned l, double *data1);
	MyArray(unsigned l, double data1);
	MyArray(unsigned l);
	MyArray();
	~MyArray();
	MyArray(const MyArray &a);
	friend ostream& operator << (ostream& out, const MyArray& a);
	friend istream& operator >> (istream& in, const MyArray& a);
	double& operator[ ](int index);
	MyArray operator = (const MyArray& a);
	MyArray operator + (MyArray& a);
};
MyArray MyArray::operator = (const MyArray& a)
{
	unsigned i;
	data = new double[a.length + 1];
	length = a.length;
	for (i = 1; i <= length; i++)
	{
		data[i] = a.data[i];
		//cout << c.data[i] << endl;
	}
	return *this;
}
MyArray::MyArray(const MyArray &a)
{
	unsigned i;
	data = new double[a.length + 1];
	length = a.length;
	for (i = 1; i <= length; i++)
	{
		data[i] = a.data[i];
	}
}
MyArray::MyArray() :length(0),data(0)
{
	int i;
	data = new double[length + 1];
	for (i = 1; i <= length; i++)
	{
		data[i] = 0;
	}
}
MyArray::MyArray(unsigned l) :length(l)
{
	int i;
	data = new double[length + 1];
	for (i = 1; i <= length; i++)
	{
		data[i] = 0;
	}
}
MyArray::MyArray(unsigned l, double data1)
{
	int i;
	length = l;
	data = new double[length + 1];
	for (i = 1; i <= length; i++)
	{
		data[i] = data1;
	}
}
istream& operator >> (istream& in, const MyArray& a)
{
	unsigned i,j;
	j = a.length;
	cout << "input length" << endl;
	in >> j;
	cout << "input data" << endl;
	for (i = 1; i <= a.length; i++)
	{
		in >> a.data[i];
	}
	return in;
}
MyArray MyArray::operator + (MyArray& a)
{
	MyArray c;
	unsigned i;
	c.length = length + a.length;
	c.data = new double[length + a.length + 1];
	for (i = 1; i <= length; i++)
	{
		c.data[i] = data[i];
	}
	for (i = length + 1; i <= length + a.length; i++)
	{
		c.data[i] = a.data[i-length];
	}
	return c;
}
MyArray::MyArray(unsigned l, double *data1)
{
	int i;
	length = l;
	if (data1)
	{
		data = new double[length + 1];
		for (i = 1; i < length; i++)
		{
			data[i] = data1[i-1];
		}
	}
	else
		data = NULL;
}
MyArray::~MyArray()
{
	if(data)
		delete[]data;
	//cout << "析构" << endl;
}
ostream& operator<<(ostream& out, const MyArray& a)
{
	int i;
	for (i = 1; i <= a.length; i++)
		out << a.data[i] << '\t'; //a[i]
	out << endl;
	return out;
}
double& MyArray::operator[ ](int index)
{
	if (index > 0 && index <= length)
		return  data[index];
	else
	{
		cout << "out of range !" << endl;
		return data[0];
	}
}
//定义构造函数及相关运算符重载函数
//注意：不得更改以下测试程序：
int main()
{
	int i;
	MyArray opr1(5);
	cout << "输出数组1的值：" << endl;
	cout << opr1;      //输出0 ,0, 0, 0, 0
	cout << "输出数组2的值：" << endl;
	MyArray opr2(3, 2);  //包含3个元素，初始值都为2

	cout << opr2;  //输出2.2,2,2,2,2
	cout << "输入3个数值：" << endl;
	//cin >> opr1;

	for (i = 1; i < 5; i++)
		opr2[i] /= i;   //数组下标从1－length, 越界访问提示错误，不做操作！
	cout << opr2;

	MyArray opr3;
	opr3 = opr2 + opr1;   // 数组的合并
	cout << "数组3的值：" << endl;
	cout << opr3;   //数组1和2的全部元素

	return 0;
}
