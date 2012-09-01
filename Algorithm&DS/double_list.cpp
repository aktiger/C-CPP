/*
@@
Author: justinzhang
Email:  uestczhangchao@gmail.com
Time:   2012-9-1 20:37:37
desc:   double list related code
*/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

template <typename type>
class doublelist
{
public:
	static const int TERMINAL = 111;
	doublelist<type>* get_next()
	{
		return next;
	}
	void set_next(doublelist<type>* ne)
	{
		this->next = ne;
	}

	doublelist<type>* get_prev()
	{
		return prev;
	}
	void set_prev(doublelist<type>* prev)
	{
		this->prev = prev;
	}

	type get_data()
	{
		return data;
	}
	void set_data(const type &data)
	{
		this->data = data;
	}
	doublelist<type> * create_doublelist();
	void show_doublelist(doublelist<type> *phead);
	doublelist<type> * create_doublelist_with_vector(vector<type> data);
private:
	doublelist<type> * next;
	doublelist<type> * prev;
	type data;
};

template<typename type> doublelist<type>* doublelist<type>:: create_doublelist()
{
	doublelist<type> *phead = new doublelist<type>();
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
	phead->data = TERMINAL;
	doublelist<type> *preal_head = phead;

	type tmp_data;
	doublelist<type> *node = NULL;
	cout << "input list data, end with " << TERMINAL << "!" << endl;
	while(1)
	{
		cin>> tmp_data;
		if(tmp_data == TERMINAL)
			break;
		node = new doublelist<type>();
		assert(node);
		node->data = tmp_data;
		phead->next = node;
		node->prev = phead;
		node->next = NULL;
		phead = node;
	}
	/* the following two statements make the list become circular link list*/
	node->next = preal_head;
	preal_head->prev = node;
	return preal_head;
}

template <typename type> void doublelist<type>::show_doublelist(doublelist<type> *phead)
{
	doublelist<type> * cur = phead;
	/* if the cur pointer points to the head pointer, it means the end of the list;
	   you can draw a draft graph to help you understatnd it;
	*/
	while(cur->next!=phead)
	{
		cur = cur->next;
		cout << cur->data << endl;
	}
}

template <typename type> doublelist<type> * doublelist<type>::create_doublelist_with_vector(vector<type> data)
{
	int i = 0;
	doublelist<type> *ptmp_head = new doublelist<type>();
	assert(ptmp_head);
	ptmp_head->next = ptmp_head;
	ptmp_head->prev = ptmp_head;
	doublelist<type> *phead = ptmp_head;
	doublelist<type> *node = NULL;
	for(i = 0; i < data.size(); i++)
	{
		node = new doublelist<type>();
		assert(node);
		node->data = data[i];
		ptmp_head->next = node;
		node->prev = ptmp_head;
		ptmp_head = node;
		node->next = NULL;
	}

	/* make it become circular doble link list */
	phead->prev = node;
	node->next = phead;
	return phead;
}

int main()
{
	doublelist<float> dlist;
	//doublelist<float> *dl1 = dlist.create_doublelist();
	//dlist.show_doublelist(dl1);

	/* test create_doublelist_with_vector */
	doublelist<int> int_dlist;
	vector<int> vec;
	for(int i=0; i<10; i++)
		vec.push_back(i+1);
	doublelist<int>* pint_dlist = int_dlist.create_doublelist_with_vector(vec);
	int_dlist.show_doublelist(pint_dlist);

	return 0;
}