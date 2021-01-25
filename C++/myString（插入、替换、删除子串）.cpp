/*ǰ���ʵ����������ƹ��ļ��ַ�����myString�����������ַ����������ַ������ȼ����ݵȹ��ܣ�����ʵ���ַ���������Ƚϣ�
���ø�������һ�����б༭���ܵĴ���edit_string������һ����ʾ����λ�õ������ݳ�Ա���������µĳ�Ա������
ʹ�����ڴ���ָ��λ�ô��Ľ��в����ַ������滻�ַ���ɾ�������Ӵ��ȱ༭���ܣ����ܲ����Ӵ���
��дһ������ʵ�ֲ������ַ�������ز�����*/

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
		while ((p = strstr(str, s2)) != NULL) {					//��s1��s2�ַ����Ҳ�����ͬԪ��ʱֹͣ��strstr�ַ��������ַ��� 
			*p = '\0';											//��s1����s2��ȵ�ͷ����Ϊ\0,�ض� 
			temp = new char[strlen(p + strlen(s2)) + 1];
			strcpy(temp, p + strlen(s2));						//��p����ӵ�s1��s2��ȵ��Ƕ�ĩβ��������   strcpy�����ַ��� 
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