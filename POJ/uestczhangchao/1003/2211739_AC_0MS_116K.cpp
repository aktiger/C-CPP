#include<iostream>
using namespace std;
int main()
{int i=2;

float length;
 
	while(length!=0.00)
	{   int	count=0;
	float len=0;
		cin>>length;

	for(i=2;len<length;i++)
	{
	len=len+1.00/i;
	count++;
	}	
if(length>=0.01&&length<=5.2)	
cout<<count<<" card(s)"<<endl;
	}

    return 0;
}