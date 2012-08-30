/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-30 16:58:38
desc:for the practice of interview problem
*/
#include <iostream>
using namespace std;
struct Foo
{
	Foo(){}
	Foo(int) {}
	void fun() {}
};

int main()
{
	Foo a(10);
	a.fun();
	//Foo b();
	//b.fun();

	const char *p1 = "hello";
	char *const p2 = "world";
	p1++;
	//*p1 = 'w'; //error
	//p2++;      // error
	//*p2 = 'h';  //error : can not write to const string

	char str[][10] = {"hello","Google"};
	char *pstr = str[0];
	cout << strlen(pstr+10) << endl; 
	/*

	str[ ][10]由定义可知，str[0]="Hello"，str[1]="Google"，

	内存中数据的存储为：

	str[0]                                       str[1]

	H e l l 0 '\0' '\0' '\0' '\0' '\0' '\0' G o o g l e '\0' '\0' '\0' '\0'

	所以p+10刚好为‘G’的地址，所以strlen(p+10)=6
	*/

	int x[4] = {0};
	int y[4] = {1};

	for(int i=0; i<4; i++)
		cout << x[i] << " " << y[i] << endl;


	return 0;
}
