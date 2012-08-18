#include<iostream>
using namespace std;
int main()
{
int i,j;

while(cin>>i>>j)
{
	int k=0;
	
while(i>0)
{k=k+i;
i=i/j;
}

cout<<k<<endl;

}



return 0;
}