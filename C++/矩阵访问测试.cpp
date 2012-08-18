/*
*
*时间：2012年3月9日13:04:00
*作者：张超
*Email:uestczhangchao@gmail.com
*/


#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;


int Mat[1000];

void fun1()
{
	int *tmp = &Mat[500];
	for (int i=0; i<100000;i++)
	{
		for (int j=0; j<1000;j++)
		{
			*tmp = 333;
		}
	}


}


void fun2()
{
	
	for (int i=0; i<100000;i++)
	{
		for (int j=0; j<1000;j++)
		{
			Mat[500]=333;
		}
	}
}



int main()
{
	SYSTEMTIME st1,st2;
	GetSystemTime(&st1);
    fun1();
	GetSystemTime(&st2);

	cout << "fun1 running time::" << endl;
	cout << "st1.wSecond:"<<st1.wSecond << " st2.wSecond" << st2.wSecond << endl;
	cout << "st1.wMilliseconds:" << st1.wMilliseconds << " st2.wMilliseconds:" << st2.wMilliseconds << endl;
	cout << "st2.wMilliseconds-st1.wMilliseconds:" << st2.wMilliseconds - st1.wMilliseconds << endl;
	cout << "*************"<< endl;

	cout << (((st2.wSecond-st1.wSecond)>0)?(st2.wSecond-st1.wSecond)*1000:0)+(st2.wMilliseconds-st1.wMilliseconds)<<endl;

	GetSystemTime(&st1);
	fun2();
	GetSystemTime(&st2);

	cout << "fun2 running time::" << endl;
	cout << "st1.wSecond:"<<st1.wSecond << " st2.wSecond:" << st2.wSecond << endl;
	cout << "st1.wMilliseconds:" << st1.wMilliseconds << " st2.wMilliseconds:" << st2.wMilliseconds << endl;
	cout << "st1.wMilliseconds:" << st1.wMilliseconds << " st2.wMilliseconds:" << st2.wMilliseconds << endl;
	cout << "st2.wMilliseconds-st1.wMilliseconds:" << st2.wMilliseconds - st1.wMilliseconds << endl;
	cout << "*************"<< endl;

cout << (((st2.wSecond-st1.wSecond)>0)?(st2.wSecond-st1.wSecond)*1000:0)+(st2.wMilliseconds-st1.wMilliseconds)<<endl;


	return 0;
}