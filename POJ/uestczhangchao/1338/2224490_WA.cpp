#include<iostream>
#include<algorithm>
using namespace std;
#include <math.h>
int main()
{
        int i,n,a,b,c;
        long d[1500];
        i = 0;
        for(a= 0; a < 32; a++)
                for(b = 0 ;b < 21; b++)
                       for(c = 0; c< 15; c++){
                              if (i>=1500) break;
                              if(pow(2,a)*pow(3,b)*pow(5,c) < 2100000000.0)
                              d[i++] = pow(2,a)*pow(3,b)*pow(5,c);
                  
                        }
sort(d,d+i+1);
for(;;)		
{
	
cin>>n;
if(n==0)  break;
cout<<d[n-1]<<endl;
 }

        return 0;
}
 
