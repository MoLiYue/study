#include<iostream>
using namespace std;
class Array
{
public:
	Array(int s=0, int n=0);
	~Array()
	{ 
		if (pArr)
			delete[]pArr;
	}
	int& operator [](int index);
	friend ostream& operator<<(ostream& out, const Array& a);
	Array& operator ++();
	Array operator ++(int);
private:
	int * pArr;
	int size;
};
Array& Array::operator ++()
{
    int i;
	for (i = 1; i < size + 1; i++)
    {
        ++pArr[i];
    }
    return *this;
}
Array Array::operator ++(int)
{
    int i;
    Array temp;
	for (i = 1; i < size + 1; i++)
    {
        temp.pArr[i] = pArr[i]++;
    }
    return temp;
}

ostream& operator<<(ostream& out, const Array& a)
{
    int i;
	for (i = 1; i < a.size + 1; i++)
        out<<a.pArr[i]<<'\t';
    return out;
}
Array::Array(int s,int num)
{
	   size = s;
	   if(size)
        pArr = new int[size + 1];
	   else
	    pArr=NULL;

	   for (int i = 0; i < size + 1; i++)
		   pArr[i] = num;
}
int& Array::operator[](int index)
{
	if (index > 0 && index < size + 1)
		return pArr[index];
    else
        {
		cout << "out of range" << endl;
            return pArr[0];
        }

}



int main()
{
	Array a(10, 1), b(5), c;
   cout << a << b << c << endl;
   cout << ++a;

  // (c = b) = a ;
  // b = a;

   return 0;
}
