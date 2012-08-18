#include<iostream>
using namespace std;
int main()
{int i=2;
float len=0;
float length;
int count=0;
cout<<"input the length of your cards:"<<endl;
    cin>>length;
	for(i=2;len<length;i++)
	{
	len=len+1.00/i;
	count++;
	}
cout<<count;
    return 0;
}