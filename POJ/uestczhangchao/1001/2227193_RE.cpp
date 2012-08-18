#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
#define N 1000

int time(int v[],int v2[])
{
 int i,j,k,c[N]={0},mid=0;
 for(i=0;i<N-1;i++)
 {
  for(j=0,k=i;j<N-1;j++,k++)
  {
   c[k]+=(v[j]*v2[i]);
   if(c[k]>=10)
   {
    c[k+1]+=c[k]/10;
	c[k]=c[k]%10;
   }
  }
 }
 for(i=0;i<N;i++) {v[i]=c[i];}
 return 0;
}

int power(int v[],int n)
{
 int i,j,len2,v2[N]={0};
 for(i=0;i<N;i++)
	 v2[i]=v[i];
 for(i=0;i<n-1;i++) 
 {
  time(v,v2);
 }
 return 0;
}

int main()
{
 char m[100]={0};
 int i,n,len,j,v[N]={0},mid,res[N+1]={0};
 while(scanf("%s %d",&m,&n)!=EOF)
 {
  len=strlen(m);
  for(i=0,j=0;i<len;i++)
  {
   if(m[len-i-1]=='.') {mid=i;continue;}
   v[j]=m[len-i-1]-48;
   j++;
  }
  mid*=n;
  power(v,n);
  for(i=0,j=0;i<N;i++)
  {
   if(i==(mid)) res[j++]=(-1);
   res[j++]=v[i];
  }
  for(i=N-1;i>=0;i--) if(res[i]!=0) break;
  for(j=0;j<N-1;j++) if(res[j]!=0) break;
  for(;i>=j;i--) 
  {
   if(res[i]<0) 
   {      
    if(i!=j) printf(".");
   }
   else printf("%d",res[i]);
  }
  printf("\n");
  memset(v,0,sizeof(v));
  memset(res,0,sizeof(res));
  memset(m,0,sizeof(m));
 }
}
