//:c08:Quoter.cpp
//random quote selection
/*
*C++编程思想第八章，关于const成员函数的例子
*这个例子说明，const对象只能调用cosnt成员函数，例子利用随机数生成器构造了
*一个选举器，每次都从若干句话中选出与上次不同的一句话，打印输出。
*时间：2011-7-17 10:34
*作者：张超
*Email:uestczhangchao@gmail.com
*/

#include "X:\编程练习\C-C++\global.h"

#if Quoter_cpp==stdon
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Quoter
{
	int lastquote;
public:
	Quoter();
	int lastQuote() const;
	const char* quote();
};

Quoter::Quoter()
{
	lastquote=-1;
	srand(time(0));
}

int Quoter::lastQuote() const
{
	return lastquote;
}

const char* Quoter::quote()
{
	static const char* quotes[]=
	{
		"Are we having fucn yet?",
		"Doctors always know best!",
		"Is it ... Atomic",
		"Fear is obscene",
		"There is no significant evidence",
		"to support the idea",
		"that life is serious",
		"Things that make us happy, make us wise",
		"This line is add by JustinZhang",
	};
	//对二维指针进行sizeof运算的结果为：（二维指针包含的一位指针的个数）×（一维指针的大小）
	const int qsize = sizeof quotes/sizeof *quotes;
	cout << "qsize=" << qsize <<" sizeof quotes="<<sizeof quotes <<" sizeof *quotes="<<sizeof *quotes << endl;
	int qnum = rand() % qsize;
	//从quotes中选择一句与上一句不同的话出来。
	while (lastquote >=0 && qnum==lastquote)
	{
		qnum = rand()%qsize;
	}
	return quotes[lastquote = qnum];
}
int main()
{
	Quoter q;
	const Quoter cq;
	cq.lastQuote();
	int a = 0;
	int c = a&&10/a;
	cout << c << endl;
	//cq.quote();
	for(int i=0; i<20; i++)
	{
		cout << q.quote() << endl;

	}
	system("pause");
}

#endif