/*
@@
	Author:	Justinzhang
	Email:	uestczhangchao@gmail.com
	Time:	2012-9-1 22:08:31
	Desc:	It's a problem meet a long time ago. i've tried to write many times;
			it also occurs at different interviews. today i write again for revies. 
			God bless~
@@
*/

#include <iostream>
#include <cassert>
using namespace std;

/*it's really a small and simple function, 
but there so many aspects to pay attention to;*/
char * strcpy(char *dest, const char *str)
{
	assert(str && dest);
	char *tmp = dest;
	while((*dest++=*str++)!=0);//this will copy '\0' to dest
	return tmp;
}

int main()
{
	char *str = "hello world!";
	char *dest = new char[strlen(str)+1]; // here it add 1 to stlen(str), cause we need a '\0'
	assert(dest);// whenever use a pointer, first to test if it is NULL; after use it up, assign NULL to it;
	cout << strcpy(dest,str) << endl;
	return 0;
}