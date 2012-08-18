#include<iostream>
using namespace std;
int main()
{float x,y,z;
int u;

int m,i=0;
	
	cin>>m;
	for(i=0;i<m;i++)
	{
	cin>>x>>y;
	z=3.14*(x*x+y*y)/100;
	u=z+1;
	cout<<"Property "<<i+1<<": This property will begin eroding in year "<<u<<'.'<<endl;
	}
	cout<<"END OF OUTPUT";
	return 0;
}
