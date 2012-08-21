/*
Author:justinzhang
Email:uestczhangchao@gmail.com
des.:to decide whether two lists intersects~~;
time:2012-8-19 9:35:28
*/

#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

typedef struct List
{
	double data;
	struct List * next;
}list, *plist;
double random(double start, double end)
{
	return 2*(start+(end - start)*rand()/(RAND_MAX+1.0));
}

plist create_list()
{
	int i = 0;
	cout << "time(0)=" << time(0)<<endl;
	srand((unsigned)time(0)*rand());
	int cnt = int(random(0,10));
	cout << "cnt=" << cnt << endl;
	plist phead = NULL;
	for(i=0; i<cnt; i++)
	{
		double tmpdata = random(0,100);
		list *tmplist = new list;
		tmplist->data = tmpdata;
		tmplist->next = phead;
		phead = tmplist;
	}
	return phead;
}
void displaylist(plist h)
{
	while(h!=NULL)
	{
		cout << h->data << endl;
		h = h->next;
	}
}

bool compare_list(plist h1, plist h2)
{
	while(h1!=NULL && h2!=NULL)
	{
		if(h1!=h2)
		{
			h1 = h1->next;
			h2 = h2->next;
		}
		else
			return true;//intersects
	}
	if(h1==NULL || h2==NULL)
		return false;//not intersects
	else
		return true;
}

int main()
{
	plist head1 = create_list();
		displaylist(head1);
	plist head2 = create_list();
	cout << "head2" << endl;
	displaylist(head2);
	if(compare_list(head1,head1))
		cout << "lists intersects" << endl;
	else
		cout << "lists not intersects" << endl;
	return 0;
}