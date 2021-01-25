#include <iostream>
using namespace std;
int fun2(int a, int b);
class Rational
{
public:
	Rational(int nn = 1, int mm = 1);
	Rational R_add(Rational &A);
	Rational R_sub(Rational &A);
	Rational R_mul(Rational &A);
	Rational R_div(Rational &A);
	void print();
private:
	void simple();
	int m;		//分母
	int n;		//分子
};

Rational::Rational(int nn, int mm)
{
	this->m = mm;
	this->n = nn;
	if (!m)
	{
		cout << "The denominator can not be zero.(Now 1)" << endl;
		this->m = 1;
	}
}

Rational Rational::R_add(Rational & A)
{
	int m_new, n_new;
	m_new = m * A.m;
	n_new = n * A.m + A.n * m;
	return Rational(n_new, m_new);
}

Rational Rational::R_sub(Rational & A)
{
	int m_new, n_new;
	m_new = m * A.m;
	n_new = n * A.m - A.n * m;
	return Rational(n_new, m_new);
}

Rational Rational::R_mul(Rational & A)
{
	int m_new, n_new;
	m_new = A.m*m;
	n_new = A.n*n;
	return Rational(n_new, m_new);
}

Rational Rational::R_div(Rational & A)
{
	int m_new, n_new;
	m_new = A.n*m;
	n_new = A.m*n;
	return Rational(n_new, m_new);
}

void Rational::print()
{
	simple();
	cout << n << "/" << m << endl;
}

void Rational::simple()
{
	int x = fun2(m, n);
	m /= x;
	n /= x;
}
int fun2(int a, int b)//迭代
{
	int c, d;
	c = (a > b ? a : b);
	d = (a < b ? a : b);
	if (!(c%d))
		return	d;
	else
		return fun2(d, c%d);
}
int main()
{
	Rational r1(1, 2);
	Rational r2(2, 3);
	Rational r3(1, 3);

	Rational r4;
	r4 = r2.R_add(r3);		//	2/3+1/3
	r4.print();

	r4 = r2.R_sub(r3);		//	2/3-1/3
	r4.print();

	r4 = r2.R_mul(r1);		//	2/3*1/2
	r4.print();

	r4 = r2.R_div(r1);		//	2/3	/	1/2
	r4.print();
	return 0;
}