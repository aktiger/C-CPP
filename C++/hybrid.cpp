/*
@@
	Author:	Justinzhang
	Email:	uestczhangchao@gmail.com
	Time:	2012-9-4 21:22:39
	Desc:	hybrid cpp problem meet during job hunting era:(
@@
*/

#include <iostream>
using namespace std;
class A
{
public:
	A(){cout << "AC"<< endl;}
	virtual ~A() {cout << "AD" << endl;}
};
class B: public A
{
public:
	B(){cout << "BC" << endl;}
	virtual ~B(){cout << "BD" << endl;}

};

class AA
{
	int a1, a2;
public:
	AA():a1(0),a2(a1)
	{
		cout << a1 << endl << a2;
	}
};

int main()
{
	A *q = new B();
	delete q;
	B *p = new B();
	delete p;

	AA a;
	return 0;
}
