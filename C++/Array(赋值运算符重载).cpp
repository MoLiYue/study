#include<iostream>
using namespace std;
class Array
{
public:
	Array(int s=0, int n=0);
	~Array(){ if(pArr)delete []pArr ; }
	int& operator[ ]( int index );
	Array& operator++( );
	Array& operator=(Array& a);
friend Array& operator++( Array&, int );
friend ostream& operator<<(ostream& out,const Array& a);
private:
	int * pArr;
	int size;
};

Array::Array(int s,int num)
{
	   size = s;
	   if(size)
        pArr = new int[size+1];
	   else
	    pArr= NULL;

	   for(int i = 1; i<=size;i++)
		   pArr[i] = num;
}
int& Array::operator[ ]( int index )
{
    if( index>0 && index<=size )
        return  pArr[index];
    else
    {   cout<<"out of range !"<<endl;
        return pArr[0];
    }
}

Array& Array::operator++( )
{
    for(int i = 1 ; i<size ; i++)
			pArr[i]++;
	return *this;
}
ostream& operator<<(ostream& out,const Array& a)
{
        out<<a.size<<" elements:";
		for(int i = 1 ; i<=a.size ; i++)
			out<< a.pArr[i]<<'\t' ; //a[i]
        out<<endl;
		return out;
}

Array&	Array::operator=(Array& a)
{
	  if(pArr) delete []pArr ;
       pArr = new int[a.size];
	   size = a.size;
       for(int i = 0; i< size; i++)
		   pArr[i] = a.pArr[i];
	   return *this;
	}

int main()
{
   Array a(10,1),b(5),c;

   cout<< (c = ++b);

   return 0;
}
