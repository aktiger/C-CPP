#include<stdio.h>
#include<math.h>
int fn(long num)
{
	if(num<=9)
		return num;
	else if(num<=189)
	{
		num-=10;
		if(num%2==0)
			return num/20+1;
		else return (num%20-1)/2%10;
	}
	else if(num<=2889)
	{
		num-=190;
		if(num%3==0)
			return num/300+1;
		else if((num-1)%3==0)
			return (num%300-1)/30;
		else if((num-2)%3==0)
			return (num%300-2)%30/3;
	}
	else if(num<=38889)
	{
		num-=2890;
		if(num%4==0)
			return num/4000+1;
		else if((num-1)%4==0)
			return (num%4000-1)/400;
		else if((num-2)%4==0)
			return (num%4000-2)%400/40;
		else if((num-3)%4==0)
			return (num%4000-3)%40/4;
	}
	else
	{
		num-=38890;
		if(num%5==0)
			return num/50000+1;
		else if((num-1)%5==0)
			return (num%50000-1)/5000;
		else if((num-2)%5==0)
			return (num%50000-2)%5000/500;
		else if((num-3)%5==0)
			return (num%50000-3)%500/50;
		else if((num-4)%5==0)
			return (num%50000-4)%50/5;
	}
}
long clj(int a1,unsigned long a,long b,int c)
{
	long low=1,high=b,mid;
	unsigned long sum,sum1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(mid<1000)
		{
			sum=(2*a1+c*(mid-1))*mid/2;
			sum1=(2*a1+c*(mid-2))*(mid-1)/2;
		}
		else
		{
			sum=((2*a1+c*(mid-1))/2)*mid;
			sum1=((2*a1+c*(mid-2))/2)*(mid-1);
		}
		if(a<=sum&&a>sum1)
			return (a-sum1-1)%(a1+c*(mid-1))+1;
		else if(sum>a)
			high=mid-1;
		else if(sum<a)
			low=mid+1;
	}
}
int main()
{
	int t,ans;
	unsigned long n;
	long num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lu",&n);
		if(n<=45)
			num=clj(1,n,9,1);
		else if(n<=9045)
			num=clj(11,n-45,90,2);
		else if(n<=1395495)
			num=clj(192,n-9045,900,3);
		else if(n<=189414495)
			num=clj(2893,n-1395495,9000,4);
		else num=clj(38894,n-189414495,90000,5);
		ans=fn(num);
		printf("%d\n",ans);
	}
}
