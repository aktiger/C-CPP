#include <stdio.h>
#include <string.h>
#include <assert.h>



int main()
{
	char data[] = "52077forever"; 
	char data2[] = "";
	//scanf();
	int i = strlen(data);
	int i2 = strlen(data2);
	
	printf("%d\n", i);
	
	for(int j=0; j<i; j++)
	{
		data[j] = data[j]^'7';
	}
	
	for(int j=0; j<i2; j++)
	{
		data2[j] = data2[j]^'9';
	}
	
	printf("%s\n",data);
	printf("%s\n",data2);
	
	getchar();
	return 0;	
}
