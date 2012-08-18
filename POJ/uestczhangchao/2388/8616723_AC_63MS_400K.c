#include <stdio.h>

int partition(int data[],int p, int r)
{
	int j;
	int i = p-1;
	int x = data[r];
	int tmp;
	for(j=p; j<=r-1;j++)
	{
		if(data[j]<x)
		{
			i++;
			tmp = data[j];
			data[j]=data[i];
			data[i] = tmp;
		}
	}

	tmp = data[i+1];
	data[i+1] = x;
	data[r]= tmp;

	return i+1;
}

void quicksort(int data[], int low, int high)
{
	int piviot;
	if(low>=high)
		return;
	if(low<high)
	{
		piviot = partition(data,low,high);
		quicksort(data,low,piviot-1);
		quicksort(data,piviot+1,high);
	}
}

int main()
{
	int middle;
	int cows[10001];
	int numberofcows;
	int i,j;
	scanf("%d\n",&numberofcows);
	for(i=1;i<=numberofcows;i++)
	{
		scanf("%d",&cows[i]);
	}
	
	/*printf("********************\n");
	for(i=1;i<=numberofcows;i++)
	{
		printf("%d\n",cows[i]);
	}
	printf("********************\n");*/

	quicksort(cows,1,numberofcows);
	middle = numberofcows/2 + 1;
	printf("%d\n",cows[middle]);
	/*	printf("********************\n");
	for(i=1;i<=numberofcows;i++)
	{
		printf("%d\n",cows[i]);
	}*/
	system("pause");
	return 0;
}