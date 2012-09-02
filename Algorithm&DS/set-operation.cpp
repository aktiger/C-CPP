/*
@@
	Author:	Justinzhang
	Email:	uestczhangchao@gmail.com
	Time:	2012-9-2 9:32:38
	Desc:	All code related to set operation.
@@
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename type> class set
{
public:
	static const int TERMINAL = 111;
	set();
	~set(){cout << "destructors\n"<< endl;}
	void intersection(const set<type> & s2);
	void union_set(const set<type> &s2);
	void show_set();
	void show_result();
	void sort_result();
	void sort_elements();
private:
	vector<type> elements;
	vector<type> result;
};
template<typename type> void set<type>::sort_result()
{
	sort(result.begin(), result.end());
}

template<typename type> void set<type>::sort_elements()
{
	sort(elements.begin(), elements.end());
}
template <typename type> set<type>::set()
{
	type input;
	cout << "input set elements, teminated by " << TERMINAL << endl;
	while(1)
	{
		cin >> input;
		if(input == TERMINAL)
			break;
		//use find to filter the same element in sets, cause don't allow same elements;
		vector<type>::iterator index = find(elements.begin(), elements.end(),input);
		if(index == elements.end())
		{
			elements.push_back(input);
		}
	}
}

template<typename type> void set<type>::show_set()
{
	for(int i=0; i<elements.size(); i++)
	{
		cout << elements[i] << endl;
	}
}

template<typename type> void set<type>::show_result()
{
	for(int i=0; i<result.size(); i++)
	{
		cout << result[i] << endl;
	}
}

template<typename type> void set<type>::intersection(const set<type>& s2)
{
	unsigned int i, j;
	for(i=0; i<elements.size(); i++)
	{
		for(j=0; j<s2.elements.size(); j++)
		{
			if(elements[i] == s2.elements[j])
			{
				result.push_back(elements[i]);
				break;
			}
		}
	}
}

template<typename type> void set<type>::union_set(const set<type>& s2)
{
	unsigned int i, j;
	result.resize(s2.elements.size());
	copy(s2.elements.begin(), s2.elements.end(), result.begin());
	for(i=0; i<elements.size(); i++)
	{
		for(j=0; j<s2.elements.size(); j++)
		{
			if(elements[i] == s2.elements[j])
				break;
		}
		if(j == s2.elements.size())
			result.push_back(elements[i]);
	}
}


int main()
{
	set<double> s1;
	//s1.show_set();
	set<double> s2;
	
	s1.intersection(s2);
	s1.show_result();
	
	s1.union_set(s2);
	s1.sort_result();
	s1.show_result();

	return 0;
}