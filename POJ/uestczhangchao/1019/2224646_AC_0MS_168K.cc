#include<iostream>
using namespace std;
int main()
{
	long long a[5]={0,45,9045,1395495,189414495};
	long long b[6]={0,1,11,192,2893,38894};
	long long c[6]={0,1,10,100,1000,10000};
	long long n,i;
    for(cin>>n;n>0;n--)
	{
		cin>>i;
		long long j;
		for(j=1;i>a[j];++j); 
		i-=a[j-1];
		long long s=b[j],f=c[j];
		for(;i>s;++f)
			s+=b[j]+(f-c[j]+1)*j;
		long long t=s-i;                                  
		for(;t>0;--f,t-=j)
			if(f<c[j])j--;                           
        if(t!=0){
			f+=1; 
			if(f>c[j]*10-1)j++;              
            t+=j;                             
			for(;t!=0;--t,f/=10);
		}
		cout<<f%10<<endl;
	}
}