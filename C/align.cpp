#include <iostream>
using namespace std;

struct TestA
{
       int a;
       char c;
       char c2;
       int b;
};

struct  Test1
{
	char b;
	int a;
	short c;
};

struct  Test2
{
	int a;
	char b;
	short c;
};

struct  Test3
{
	
	char a:1;
	char b:2;
	long c:3;
	char d:2;
};



int main()
{
	cout <<"sizeof(Test1)="<<sizeof(Test1)<<" sizeof(Test2)="<<sizeof(Test2)<<" sizeof(Test3)="<<sizeof(Test3)<<endl;
    cout << sizeof(TestA) << endl;
    system("pause");
    return 0;
    
}
