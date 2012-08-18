#define M 21
#include<iostream>
using namespace std;
 #include<math.h>
int main(){
	int i,j,n,sum; 
	int a[M],b[M];
	for(;;)
	{int sum1=0;
 		cin>>n;
 		if(n==0) break;
 		sum=0;
 		for(i=1;i<n;i++)
		{
 		    sum=sum+i*i;
 			if(n==(i*i+i)/2)
			sum1=sum;

 	  	   else if(n>(i*i-i)/2&&n<=(i*i+i)/2){
 				sum1=sum-((i*i+i)/2-n)*i;
 			}
 		}
	a[i]=n;
	b[i]=sum1;
 	}
	for(j=0;j<i;j++)
	{cout<<a[j]<<' '<<b[j]<<endl;}

 return 0;
}
 
 
