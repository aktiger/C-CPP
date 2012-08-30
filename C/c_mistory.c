/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-30 23:08:19
desc: c mistory , from coolshell.cn
*/

/*
block device will ouput under conditions:
1)buffer is full
2)encountered \n
3)user call fflush()
4)program exit

In this example, we will first get hello-std-err, then we get hello-std-out;
The reason is apparantly, because stdout is block device, the four conditions
list above is not meet, so it will not ouput its buffer; but stderr is not
block device, it will output the time you call fprintf, so hello-std-err is 
first appeared, then the program exit, fprintf output its bufffer, that's the
reasult:hello-std-out
*/
#include <stdio.h>
#include <stdlib.h>


int main()
{
fprintf(stdout,"hello-std-out");//note that stdout is block device
fprintf(stderr,"hello-std-err");//note thar stderr is not block device
exit(0);
}

