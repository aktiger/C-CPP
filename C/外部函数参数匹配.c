#include <stdio.h>
#include <stdlib.h>

char *r, *malloc();
int add_two(int x, int y);

int main()
{
	int x = add_two(3,5);
	r = malloc(3);
	r[0] = 'l';
	r[1] = 'u';
	r[2]='\0';

	printf("x=%d\n",x);
	if (!r)
	{
		
		printf("null pointer!!\n");
	}
	else
	{
		printf("not null pointer!!\n");
		printf("%s\n",r);
		free(r);
	}

	return 0;
}