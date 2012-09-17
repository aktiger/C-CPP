/*
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-14 20:23:45
Desc:	for the purpose of practicing huawei programming test;
*/

#include <stdio.h>
#include <stdlib.h>
#define array_len(array, type) (sizeof(array))/(sizeof(int))

/*
compare two array from the end element to the first element, return the number of difference
 elements
*/
int compare_array( int len1, int array1[], int len2, int array2[] )
{
	unsigned int count = 0;
	int i = len1-1, j=len2-1;
	while(i>=0 && j>=0)
	{
		if(array1[i] != array2[j])
			count++;
		i--; j--;
	}

	return count;
}

void josephus(void)
{
	int number_child = 0;
	int number_get_out = 0;
	char names[65][15];
	int i = 0;
	printf("please input number of children\n");
	scanf("%d", &number_child);
	printf("please input the number to get out\n");
	scanf("%d", &number_get_out);
	for(i=0; i<number_child; i++)
	{
		printf("input child's name\n");
		scanf("%s",names[i]);
	}




}


void strReplace(char *strsrc ,char *strreplace ,char *strfind)
{
 int i ,j=0 ,m,n,k,t;
 for(i = 0 ;strsrc[i] !='\0' ;i++)
 {
  j = 0;
  if(strsrc[i] == strfind[j])
  {
   m = i;
   n = j;
   while(strsrc[m]==strfind[n]&&(strsrc[m] !='\0')&&(strfind[n]!='\0'))
   {
    m++;
    n++;
   }
   if(strfind[n]=='\0')
   {
    t= 0;
    for(k = i ;k<m;k++)
    {
     strsrc[k] = strreplace[t];
     t++;
    }
   printf("%s\n",strsrc);
   }

  }
 }
}


typedef struct LinkNode
{
 int data;
 struct LinkNode *next;
}node;


void JOSEPHUS(int n, int m,int k)
{
   node *p  ,*r ,*list,*tmp;
     int i ,j ,x;
   list = NULL;
   r = (node*)malloc(sizeof(node));
  
   for(i = 0 ;i < n ;i++)
   {
    p = (node*)malloc(sizeof(node));
    printf("输入节点数据");
    scanf("%d",&x);
    p->data = x;
    if(list == NULL)
    {
     list = p;

    }
    else
    {
     r->next = p;
    }
    r = p;
    
   }
   p->next = list;
   p = list;
   for(i = 0 ;i<k-1;i++) //找到第一个数
   {
       tmp=p;
    p = p->next;
   }
   while(p->next != p)
   {
    for(i = 0 ; i<m-1 ;i++)
    {
     tmp= p;
     p = p->next;
    }
    tmp->next = p->next;
    printf("要删除的数据:%d\n",p->data);
    free(p);
    p = tmp->next;
   }
   if(p->next == p)
   {
    printf("要删除的数据:%d\n",p->data);
   }

}



int main()
{
	/* test compare_array */
	int array1[]={77,21,1,3,5,7};
	int array2[]={1,3,5};
	//printf("%d\n",compare_array(array_len(array1,int), array1, array_len(array2,int),array2));
	
	char strsrc[]="abcdecde";
	char strfind[]="cde";
	char strreplace[]="www";
	strReplace(strsrc ,strreplace ,strfind);
	printf("%s\n",strsrc);
	//JOSEPHUS(9,5,1);

	putchar(97);
	return 0;
}


