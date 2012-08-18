#include<iostream>
using namespace std;
int main()
{float x,y,z;
int m,i=0;
	
	cin>>m;
	for(i=0;i<m;i++)
	{int k=0;
	cin>>x>>y;
	z=3.14*(x*x+y*y)/2;
	while(50*k<z)
	{
		k++;
	}
	cout<<"Property "<<i+1<<": This property will begin eroding in year "<<k<<'.'<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
