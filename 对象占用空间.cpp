///*
//*
//*时间：2012年3月13日13:48:28
//*作者：张超
//*Email:uestczhangchao@gmail.com
//*/
//
//
//#include <iostream>
//using namespace std;
//
//
//class A
//{
//public:
//	int a;
//	int b;
//	/*virtual int func(int x)
//	{
//		return 9;
//	}*/
//	static int add(int x, int y);
//	int sub(int x, int y);
//protected:
//private:
//};
//
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	A a;
//	cout << sizeof(a) << endl;
//	return 0;
//}


#include <iostream>
using namespace std;
int main()
{
	for(int i=1; i<=100; i++)
	{
		if(i%3==0)
		{
			if(i%5==0)
				cout << "FizzBuzz" << endl;
			else
				cout << "Fizz" << endl;
		}
		else if(i%5==0)
		{
			if(i%3==0)
				cout << "FizzBuzz" << endl;
			else
				cout << "Buzz" << endl;

		}
		else
			cout << i << endl;

	}
	return 0;
}