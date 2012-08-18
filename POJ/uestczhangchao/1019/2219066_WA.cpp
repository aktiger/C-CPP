#include<iostream>
using namespace std;
int main()
{int a[80];int i,j,k,n,x;
for(i=0;i<80;i++)
{a[i]=i;
}


cin>>n;
for(j=0;j<n;j++)
{cin>>x;
for(i=0;i<80;i++)
{if(x==i)
cout<<a[i]<<endl;
}
}
return 0;
}