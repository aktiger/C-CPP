/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-19 14:14:07
desc:
	There are two strings,
	String 1: ABCDEFGHLMNOPQRS 
	String 2: DCGSRQPOM 
	using the fatest method to decide, whether one char in string 2 is also in
	string 1;
I used to meet this problem on sb's blog, now i want to implemnt int..
*/

#include<iostream>
#include<string>
using namespace std;

/*
we assume that string 2 is shorter than string1.
*/
bool brute_force(const string &str1, const string &str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	int i, j, flag = -1;
	for(i=0; i<len2; i++)
	{
		flag = -1;
		for(j=0; j<len1; j++)
		{
			if(str2[i]==str1[j])
			{
				flag = 0;
				break;
			}
		}
		if(flag==-1)
		{
			break;
		}
	}
	if(i==len2)
		return true;
	else
		return false;
}


int main()
{
	string str1, str2;
	cin>>str1;
	cout << str1 << endl;
	cin>>str2;
	cout << str2 << endl;
	cout << brute_force(str1,str2) << endl;
	return 0;
}



