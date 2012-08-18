#include<iostream>
using namespace std;
int main()
{double a[12],sum=0,averge;
for(int i=0;i<12;i++)

{cin>>a[i];
}
for( i=0;i<12;i++)
{sum+=a[i];
}
averge=sum/12;
cout<<"$"<<averge;
return 0;
}