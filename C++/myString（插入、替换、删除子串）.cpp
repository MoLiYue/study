/*前面的实验中曾经设计过的简单字符串类myString，包含输入字符串、返回字符串长度及内容等功能，并能实现字符串连接与比较；
利用该类派生一个具有编辑功能的串类edit_string，增加一个表示串中位置的新数据成员，并增添新的成员函数，
使其能在串中指定位置处的进行插入字符串、替换字符和删除后续子串等编辑功能，并能查找子串。
编写一个程序，实现并测试字符串的相关操作。*/

#include<cstring>
#include<iostream>

using namespace std;

class myString
{
protected:
	char *str;
public:
	myString(const char*a) :str(NULL) {
		if (a)
		{
			str = new char[strlen(a) + 1];
			strcpy_s(str, strlen(a) + 1, a);
		}
		else
		{
			str = new char[8];
			strcpy_s(str, 8, "no str");
		}
	}
	int strlenth() {
		if(str)
			return strlen(str);
	}
	char* getstring(const char*a) {
		if (a)
		{
			str = new char[strlen(a) + 1];
			strcpy_s(str, strlen(a) + 1, a);
		}
		else
		{
			str = new char[8];
			strcpy_s(str, 8, "no str");
		}
		return str;
	}
	~myString() { delete[]str; }
	friend ostream& operator <<(ostream& out, myString &a) {
		out << a.str << endl;
		return out;
	}
	void strcompare(myString& a) {
		if (strcmp(str, a.str) == 0)
			cout << "the same" << endl;
		else
			cout << "different" << endl;
	}
	char* strconnect(myString& a) {
		strcat(str, a.str);
		return str;
	}

};
class edit_string :public myString
{
protected:
	int index;
public:
	edit_string(const char* &a) :myString(a) {
		index = 0;
	}
	void addinsp(int a,const char* c = NULL) {
		index = a - 1;
		char* tempback;
		int i, j;
		tempback = new char[strlen(str) + 1-index];
		for (i = index,j = 0; i <= strlen(str)+1;j++, i++)
		{
			tempback[j] = str[i];
		}
		for (i = index,j= 0; j <= strlen(c); j++,i++)
		{
			str[i] = c[j];
		}
		for (i = strlen(str), j = 0; j < strlen(tempback); j++, i++)
		{
			str[i] = tempback[j];
		}
	}
	void extrsp(int a) {
		index = a - 1;
		char c;
		cout << "inputChar" << endl;
		cin >> c;
		str[index] = c;
	}
	void deleteStr(const char* s2) {
		char *p,*temp;
		while ((p = strstr(str, s2)) != NULL) {					//在s1和s2字符中找不到相同元素时停止，strstr字符串中招字符串 
			*p = '\0';											//把s1自与s2相等的头处改为\0,截断 
			temp = new char[strlen(p + strlen(s2)) + 1];
			strcpy(temp, p + strlen(s2));						//把p向后延到s1与s2相等的那段末尾处拷贝到   strcpy拷贝字符串 
			strcat(str, temp);
		}
	}
	int findStr(const char* s2) {
		char* p1;
		p1 = strstr(str, s2);
		return (p1 - str + 1);
	}
	void print() {
		cout << str << endl;
	}
};
int main()
{
	int i;
	const char* a = "hello world, world!", *c = "worl";
	edit_string str1(a);
	//str1.deleteStr(c);
	//str1.print();
	i = str1.findStr(c);
	cout << i << endl;
	/*str1.addinsp(7,c);
	str1.print();
	str1.extrsp(7);
	str1.print();*/
}