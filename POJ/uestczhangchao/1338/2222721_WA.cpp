#include<iostream>
#include<algorithm>
using namespace std;
#include <math.h>
int main()
{
        int i,n,i1,i2,i3;
        int a[2500];
        i = 0;
        for(i1 = 0; i1 < 21; i1++)
                for(i2 = 0 ;i2 < 32; i2++)
                        for(i3 = 0; i3 < 15; i3++)
                                if(pow(2,i1)*pow(3,i2)*pow(5,i3) < 2100000000.0)
								{
                                                a[i++] = pow(2,i1)*pow(3,i2)*pow(5,i3);
                                }
        sort(a,a+i+1);
for(;;)		
{
	
cin>>n;
if(n==0)  break;
cout<<a[n]<<endl;
        }

        return 0;
}

