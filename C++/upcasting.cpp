/*
Author:justinzhang
Email:uestczhangchao@gmail.com
Time:2012-11-27 21:58:56
Desc: this program is used to learn the effect of upcasting.
*/

#include <iostream>
using namespace std;

class human
{
	public:
		void talk()
		{
			cout << "in human" << endl;
		}
};

class female:public human
{
	public:
		void talk()
		{
			cout << "female " << endl;
		}
};

/*pointer style*/
void talk1(human *h)
{
	h->talk();
}
/*value style*/
void talk2(human h)
{
	h.talk();
}

int main()
{
	female f;
	talk1(&f);
	talk2(f);
	return 0;
}




