 #include<iostream>
 using namespace std;
 #include<math.h>
 int main(){
 	int i;
	int M;
	int sum;
	int sum1=0;
	for(;;)
	{
 	     cin>>M;
 		if(M==0) break;
 		sum=0;
 		for(i=1;i<=M;i++)
		{
 			sum=sum+i*i;
 			if(M==(i*i+i)/2) sum1=sum;
			
 				
 			else if(M>(i*i-i)/2&&M<=(i*i+i)/2){
				sum1=sum-((i*i+i)/2-M)*i;
 			}
 		}
		cout<<M<<' '<<sum1<<endl;
 	
 	}

	return 0;
 }
 
 