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
	*p2 = 'h'; 

	/*int x[4] = {0};
	int y[4] = {1};

	for(int i=0; i<4; i++)
		cout << x[i] << " " << y[i] << endl;*/


	return 0;
}
