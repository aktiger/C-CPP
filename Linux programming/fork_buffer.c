/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-30 22:53:33
desc: from a interview question, fork plus printf buffer is a littel tricky~~
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
int i = 0;
for(i=0; i<2; i++)
{
	fork();
	printf("-");
	fflush(stdout);
//	printf("-\n");
}
exit(0);
}
