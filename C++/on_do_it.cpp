/*
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-3 22:13:11
Desc:	this program is from tencent test...
		some what a fun program
*/

#include <iostream>
using namespace std;
template<typename T>
class A
{
public:
	void doint()
	{
		T *pT = (T *) this;
		pT->ondoit();
	}
	void ondoit()
	{
		cout << " A:: ondoit" << endl;
	}
	
};

class B:public A<B>
{
	public:
		void ondoit()
		{
			cout << "B<A>::ondoit" << endl;
		}
};

int main()
{
   B b;
   b.ondoit();
   A<B> a;
   a.doint();
   return 0;
}

