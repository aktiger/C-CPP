#include<iostream>
using namespace std;
int main()
{
int i,j;
while(cin>>i>>j)
{
int k=i;	
while(i>0)
{k=k+i/j;
 i=i/j+i%j;
 if(i<j)
	 break;
}
cout<<k<<endl;
}
return 0;
}