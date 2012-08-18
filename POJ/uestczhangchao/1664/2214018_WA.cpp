
#include<iostream>
using namespace std;
int disk[12],i,j,M,N,m,n,l,num=1,platenum=2;
void main()
{
	void plate();
	scanf("%d",&n);
	for(l=0;l<n;l++){
	num=1;
	scanf("%d",&M);
	scanf("%d",&N);
	disk[0]=M;
	for(m=1;m<N;m++){
		disk[m]=0;
	}
	j=0;
	for(i=2;i<=N;i++)
	{
        disk[0]=M;
	    for(m=1;m<N;m++){
		    disk[m]=0;
		}
	    plate();
	}
	printf("%d\n",num);
	}
}
void plate(){
	if((disk[j]-disk[j+1]<=1)&&(j==0)) return;
	else if(j==i-1){
		j--;
		plate();
	}
	else if(disk[j]-disk[j+1]<=1){
		j--;
		plate();
	}
	else{
		disk[j]--;
		disk[j+1]++;
		j++;
		if(disk[i-1]!=0)
                 num++;
		plate();
	}
}
