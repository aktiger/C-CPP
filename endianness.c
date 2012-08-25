/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-25 11:59:13
desc: to decide the endian of a system, endian_ness is from linux source code
*/
#include <stdio.h> 
#define Little_endian 0
#define Big_endian 1

int testbyteorder()
{
	short int word = 0x0001;
	char *byte = (char *)&word;
	return (byte[0]?Little_endian:Big_endian);
}
static union {char c[4]; unsigned long l;} endian_test = {'l','?','?','b'};
#define ENDIAN_NESS ((char)endian_test.l)

int main()
{
	printf("endian is %d\n",testbyteorder());
	printf("%c\n",ENDIAN_NESS);
	return 0;
}
