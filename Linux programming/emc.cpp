/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-10-30 13:37:38
desc: this program is used to test the program meet during emc written test
*/

#include<iostream>
#include<unistd.h>
using namespace std;
 
int main()
{
int i = 1;
if(!fork()) i++;
cout << i << endl;

if(!fork()) i++;
cout << i << endl;

return 0;
}



