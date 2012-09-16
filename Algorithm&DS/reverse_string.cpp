/*
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-10 23:09:38
Desc:	This program is used to reverse a string,e.g:abcd->dcba;
		Using recursive method we can think like this, first we assume we have
		reversed bcd->dcb, then add a to dcb, we get dcba;
*/


#include <iostream>
#include <string>
using namespace std;

string Reverse(string str)
{
	/*if(str.size()<2)
		return str;*/

	string tmp;
	if(!str.empty())
	{
		tmp = Reverse(str.substr(1));
		tmp += str[0];
	}
	return tmp;
}

void reverse_string(char *s)
{
	if(s==NULL)
		return ;
	char tmp;
	char *end = s;
	while(*end)
	{
		++end;
	}
	--end;
	while(s < end)
	{
		tmp = *s;
		*s++ = *end;
		*end-- = tmp;
	}
}

int main()
{
	string str("abcd");
	char s[] = "1234";
	s[4] = '\0';
	reverse_string(s);
	cout << s << endl;
	string t = Reverse(str);
	cout << t << endl;
	return 0;
}