#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int> intvec;
	char ss,c;
	int N,temp;
	cin>>N;
	c = cin.get(); 
	for(int i=0;i<N;i++)
	{
		temp=0;
		while((ss=cin.get())!='\n')
		{
			if (ss>='0' && ss<='9')
			{
				temp=temp*10+(ss-'0');
			}
			else if(ss>='A' && ss<'Q')
			{
				temp=temp*10+(ss-'A')/3+2;
			}
			else if(ss>'Q' && ss<'Z')
			{
				temp=temp*10+(ss-'Q')/3+7;
			}
		}
		intvec.push_back(temp);
	}
	sort(intvec.begin(),intvec.end());
	int count,tmp;
	unsigned int it=0;
		for(it=0;it<intvec.size();it++)
		{
		count=1;
		tmp=intvec[it];
		if(it>=intvec.size())
		{
			break;
		}
		while(it+1<intvec.size() && intvec[it]==intvec[it+1])
		{
			count++;
			it++;	
		}
		if(count>1)
			{
				cout.width(3);
				cout<<tmp/10000;
				cout<<"-";
				cout.width(4);
				cout<<tmp%10000;
				cout<<" "<<count<<endl;	
				count=1;
			}
		
		}
	return 0;
}