#include<iostream>
using namespace std;
 #include<math.h>
int main(){
     int i,j,n,sum;  int sum1=0;int k=0;
	 int a[50],b[50];
	for(;;)
	{
	    cin>>n;
 		if(n==0) break;
 		sum=0;
 		for(i=1;i<n;i++)
		{
 		   sum=sum+i*i;
 			if(n==(i*i+i)/2)
			sum1=sum;

 	  	   else if(n>(i*i-i)/2&&n<=(i*i+i)/2)
 				sum1=sum-((i*i+i)/2-n)*i;
 			
 		}
	a[k]=n;
	b[k]=sum1;
	k++;
 	}
	for(j=0;j<k;j++)
	{cout<<a[j]<<' '<<b[j]<<endl;}

 return 0;
}
 
 
