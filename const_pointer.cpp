	
#include<iostream>
using namespace std;
int main()
{
	const int i=10;
	int *p=(int *)&i;
	*p=20;
	cout<<i<<endl;
	return 0;
}
