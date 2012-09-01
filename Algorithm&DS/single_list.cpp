/*
@@
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-9-1 18:51:44
desc: all the list related operation will be place here;
	  including:
	  1> combine_list(list<type> *l1, list<type>* l2);
	  2> list_intersect(list<type> *l1, list<type> *l2)
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
	bool list_intersect(list<type> *l1, list<type> *l2);
	type random(type begin, type end);
	type get_data()
	{
		return data;
	}
	void set_data(const type data)
	{
		this->data = data;
	}
	list<type> * get_next()
	{
		return next;
	}
	void set_next(list<type> *ne)
	{
		this->next = ne;
	}
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

/* create list with a head */
template <typename type> list<type>* list<type> :: create_list()
{
	type tmp_data;
	list<type> *phead = new list<type>();
	phead->next = NULL;
	list<type> *real_head = phead;
	phead->data = 11;
	
	cout << "input data, end with 111" << endl;
	while(1)
	{
		cin >> tmp_data;
		if(tmp_data == 111)
			break;
		else
		{
			list<type> *node = new list<type>();
			node->data = tmp_data;
			node->next = NULL; // do not forge this line, it's very important!
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

template <typename type> bool list<type>::list_intersect(list<type>*l1, list<type>*l2)
{
	while(l1->next!=NULL && l2->next!=NULL)
	{
		l1 = l1->next;
		l2 = l2->next;
		
		if(l1==l2)
			return true;
	}
	if(l1->next==NULL || l2->next==NULL)
		return false;
	else // this will not happen, but without these two lines, there will be warnings:(
		return true;
}


int main()
{
	list<double> l1;
	list<double>* p1=l1.create_list();
	//l1.show_list(p1);

	list<double> l2;
	list<double>*p2 = l2.create_list();
	//l2.show_list(p2);

	/* test combine_list(p1,p2) */
	list<double>*p1_p2 = l2.combine_list(p1,p2);
	l2.show_list(p1_p2);

	/* test list_intersect, in oreder to make up two intersected lists,
	   i will manually create them.
	*/
	/*----------l3 initial-------------*/
	list<double> *l3_real = NULL;
	list<double> *l3_head = new list<double>();
	l3_head->set_data(111);
	l3_real = l3_head;

	list<double> *node1 = new list<double>();
	node1->set_data(1);
	l3_head->set_next(node1);
	l3_head = node1;

	list<double> *node2 = new list<double>();
	node2->set_data(2);
	node2->set_next(NULL);
	l3_head->set_next(node2);
	l3_head = node2;

	/* this is the commmon node of l3 and l4 */
	list<double> *common_node = new list<double>();
	common_node->set_data(3456);
	common_node->set_next(NULL);
	l3_head->set_next(common_node);
	l3_head = common_node;

	/*--------l4 initial----------*/
	list<double> *l4_real = NULL;
	list<double> *l4_head = new list<double>();
	l4_head->set_data(111);
	l4_real = l4_head;

	list<double> *node3 = new list<double>();
	node1->set_data(3);
	l4_head->set_next(node3);
	l4_head = node3;

	list<double> *node4 = new list<double>();
	node4->set_data(4);
	node4->set_next(NULL);
	l4_head->set_next(node4);
	l4_head = node4;

	/* l4 also points to common_node */
	l4_head->set_next(common_node);
	l4_head = common_node;

	if(l2.list_intersect(l3_real,l4_real))
	{
		cout << "l3 and l4 have common elements\n";
	}
	else
	{
		cout << "l3 and l4 have no common elements\n";
	}

	if(l2.list_intersect(p1, p2))
	{
		cout << "p1 and p2 have  common element" << endl;
	}
	else
	{
		cout << "p1 and p2 have no common element" << endl;
	}


	return 0;
}