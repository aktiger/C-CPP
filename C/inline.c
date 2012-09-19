/*
Author:	justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-18 22:17:09
Desc:	this file is used to learn the mechanism fo inline fuction;
	from this program, i learn from the following:
	1> when we use a inline function, the compiler will insert 
	   the inline function's assembly code into the calling place;
	2> if we use inline extern to modify a function, the inline function 
	   will not unfold,that is there will be no sth like...
	   add:
	      push...
	      add
	3> if we use inline static to modify a function and we didn't assign 
	   the inline function to a function pointer, it will not unfold,
	   but if we assign the inline function to a function pointer, it will
	   unfold;
	4> if we don't use extern or static to modify the inline function,
	   it will still unfold
*/

#include <stdio.h>

inline int static add(int x, int y) __attribute__((always_inline));
extern inline int sub(int x, int y) __attribute__((always_inline));

inline int add(int x, int y)
{
	return x+y;
}

inline int sub(int x, int y)
{
	return x-y;
}


int main()
{
int y = add(1,2);
int z = sub(1,2);
int (*p)(int,int) = add;
//printf("%.512f\n",5);
//printf("%e\n",5);
//printf("%d\n",5.01);
return 0;
}

