#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
void Swap(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}
void Swap(char* const a, char* const b)
{
	int i = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
	char* const c = new char[i + 1];
	strcpy_s(c, i + 1, a);
	strcpy_s(a, i + 1, b);
	strcpy_s(b, i + 1, c);
}
int main( )
{
	
	//交换两个int型变量中的数据
	int m = 3, n = 5;
	double nn = 5.5;
    cout << "m=" << m << "  n=" << n << endl;
	swap(m, n);
	//Swap(m, n);
    cout << "m=" << m << "  n=" << n << endl;
    cout << "-------------------" << endl;


    //交换两个char型变量中的数据
	char c1 = 'A', c2 = 'a';
	cout << "c1=" << c1 << "  c2=" << c2 << endl;
	swap(c1, c2);
	//Swap(c1, c2);
    cout << "c1=" << c1 << "  c2=" << c2 << endl;

	char* pc1 = &c1, *pc2 = &c2;
	cout << "*pc1=" << *pc1 << " *pc2=" << *pc2 << endl;
	swap(pc1,pc2);
	cout << "*pc1=" << *pc1 << " *pc2=" << *pc2 << endl;
	Swap(pc1, pc2);
	cout << "*pc1=" << *pc1 << " *pc2=" << *pc2 << endl;
    cout << "-------------------" << endl;

	char* p1 = (char*)"ssdut", * p2 = (char*)"dlut";
	char a1[] = "ssdut", a2[] = "dlut";
	cout << "p1:" << p1 << "\np2:" << p2 << endl;
	swap(p1,p2); 
	cout << "p1:" << a1 << "\np2:" << a2 << endl;
	Swap(a1,a2);
	cout << "p1:" << a1 << "\np2:" << a2 << endl;
	cout << "-------------------" << endl;


	string s1 = "Hello", s2("world");
	cout << "s1:" << s1 << endl << "s2:" << s2 << endl;
	swap(s1, s2);
	Swap(s1, s2);
	cout << "s1:" << s1 << endl << "s2:" << s2 << endl;
	cout << "-------------------" << endl;


	return 0;
}


