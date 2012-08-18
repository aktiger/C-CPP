//:c08:Quoter.cpp
//random quote selection
/*
*C++���˼��ڰ��£�����const��Ա����������
*�������˵����const����ֻ�ܵ���cosnt��Ա�������������������������������
*һ��ѡ������ÿ�ζ������ɾ仰��ѡ�����ϴβ�ͬ��һ�仰����ӡ�����
*ʱ�䣺2011-7-17 10:34
*���ߣ��ų�
*Email:uestczhangchao@gmail.com
*/

#include "X:\�����ϰ\C-C++\global.h"

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
	//�Զ�άָ�����sizeof����Ľ��Ϊ������άָ�������һλָ��ĸ���������һάָ��Ĵ�С��
	const int qsize = sizeof quotes/sizeof *quotes;
	cout << "qsize=" << qsize <<" sizeof quotes="<<sizeof quotes <<" sizeof *quotes="<<sizeof *quotes << endl;
	int qnum = rand() % qsize;
	//��quotes��ѡ��һ������һ�䲻ͬ�Ļ�������
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