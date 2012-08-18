#include<iostream>
using namespace std;
int main()
{int i=2;
float len=0;
float length;
int count=0;
cout<<"input the length of your cards:"<<endl;
    cin>>length;
	if(length!=0.00)
	{
	for(i=2;len<length;i++)
	{
	len=len+1.00/i;
	count++;
	}
	}
if(length>=0.01&&length<=5.2)	
cout<<count<<"card(s)"<<endl;
    return 0;
}