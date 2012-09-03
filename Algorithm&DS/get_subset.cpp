/*
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-3 11:00:14
Desc:	get all subset of a set, i used to solve this problem, when i was still a freshman;
		still remember, i was at west a teaching building at night, i use the bits of a number
		to represent the select or not select of given number from the set;
*/


#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<typename type> list<list<type>> get_subset(list<type>& set)
{
	list<list<type>> subsets;
	list<type> asubset;

	unsigned int size = set.size();
	unsigned int numberofsubset = 1 << size;

	list<type>::iterator it;
	for(unsigned int i = 0; i < numberofsubset; i++)
	{
		it = set.begin();
		int k = i;
		asubset.erase(asubset.begin(),asubset.end());
		while (k)
		{
			if (k & 1)
			{
				asubset.push_back(*it);
			}
			it++;
			k = k >> 1;
		}
		subsets.push_back(asubset);
	}
	
	return subsets;
}

template <typename type> void show_list(list<type> data)
{
	for(list<type>::iterator it = data.begin(); it != data.end(); it++)
		cout << *it << endl;
}

int main()
{
	int data[] = {1, 2, 3, 4};
	list<int> set;
	set.assign(data, data + sizeof(data)/sizeof(int));
	
	//show_list(set);

	list<list<int>> subsets = get_subset(set);
	int count = 0;
	for(list<list<int>>::iterator it = subsets.begin();it != subsets.end(); it++)
	{
		show_list(*it);
		cout << "------"<< ++count << "---------" << endl;
	}

	return 0;
}