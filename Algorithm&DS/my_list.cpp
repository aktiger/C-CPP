/*
@@
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-9-1 18:51:44
desc: all the list related operation will be place here;
	  including:
	  1> combine_list(list<type> *l1, list<type>* l2);
@@
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
template <typename type>
class list
{
public:
	list<type>* create_list();
	void show_list(list<type> *lhead);
	list<type>* combine_list(list<type> *l1, list<type>* l2);
	type random(type begin, type end);
private:
	type data;
	list<type> *next;
};

template<typename type> type list<type>::random(type begin, type end)
{
	return (begin + (end - begin)*rand()/(RAND_MAX+1));
}

template<typename type> void list<type>::show_list(list<type> *l)
{
	while(l->next!=NULL)
	{
		l = l->next;
		cout << l->data << endl;

	}
}

template <typename type> list<type>* list<type> :: create_list()
{
	type tmp_data;
	list<type> *phead = new list<type>();
	phead->next = NULL;
	list<type> *real_head = phead;
	phead->data = -999;
	
	cout << "input data, end with -999" << endl;
	while(1)
	{
		cin >> tmp_data;
		if(tmp_data == -999)
			break;
		else
		{
			list<type> *node = new list<type>();
			node->data = tmp_data;
			phead->next = node;
			phead = node;
		}

	}
	return real_head;
}

template<typename type> list<type>* list<type>::combine_list(list<type>*l1, list<type>*l2)
{

	if(l1->next==NULL)
		return l2;
	if(l2->next == NULL)
		return l1;
	list<type> * head = l1;//record the head of l1, we will link l2 after l1
	/* get last element of l1*/
	while(l1->next!=NULL)
		l1 = l1->next;
	l1->next = l2->next;
	return head;
}


int main()
{
	list<double> l1;
	list<double>* p1=l1.create_list();
	//l1.show_list(p1);

	list<double> l2;
	list<double>*p2 = l2.create_list();
	//l2.show_list(p2);

	list<double>*p1_p2 = l2.combine_list(p1,p2);
	l2.show_list(p1_p2);
	return 0;
}