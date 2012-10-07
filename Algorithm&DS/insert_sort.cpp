/**
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-20 21:46:29
Desc:	for the purpose of practicing inserting sort.
**/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

template <typename type>
type random(type begin, type end)
{
	srand(time(NULL));
	return begin+(end-begin)*rand()/RAND_MAX;
}

template <typename type>
void insert_sort(type data[], int len)
{
	/*data in range[0,len)*/
	size_t i, j;
	type key;
	for(j=1; j<=len-1; j++)//scaning from the second elements
	{
	// i need to be zero,cause if this for loop terminate normally i equal -1,
	// which means k is the smallest element.
		key = data[j];
		for(i=j-1; i>=0; i--) 
		{
			//if key is smaller than data[i], move data[i] backwards.
			if(key < data[i])
			{
				data[i+1] = data[i];
			}
			else
			{
				break;
			}
		}
		data[i+1] = key;
	}
}

int main()
{
	size_t i = 0;
	int data[10]={9,4,5,2,4,1,-1,-2,4,99};
	//for(i=0; i<10; i++)
	//{
	//	data[i] = i;
	//}

	insert_sort<int>(data, sizeof(data) / sizeof(int));
	for(i=0; i<10; i++)
		cout << data[i] << ",";
	cout << endl;
	return 0;
}


