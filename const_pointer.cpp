	
#include<iostream>
using namespace std;
int main()
{
	const int i=10;
	int *p=(int *)&i;
	*p=20;
	cout << typeid(&i).name() << endl;
	cout<<i<< " " << *p <<endl;
	cout << p << " " << &i << endl;
	return 0;
}
