/*
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-8 14:43:43
Desc:	This is a kind of knapsack problem, given a bag with capacity T and N objects
		whose capacity is 1,2,...n; Find all subsets of objects that will full the bag exactly.
		The first time i meet this problem is on the data structure book when i was a sophomore.
		At that time i use the objects power set to traverse the hole solution space.
		Here i want to use back track method to solve it.
*/
#include <iostream>
#include <list>
using namespace std;
static int count = 0;

template <typename type> void find_solution(type t, type n)
{
	static list<type> li;
	if(t<=0 || n<=0)
		return ;
	if(t==n)
	{
		count++;
		li.reverse(); // to ensure descending order
		for(list<type>::iterator it=li.begin(); it!=li.end(); it++)
			cout << *it << " ";
		cout << n << endl;
		li.reverse(); // back up list to previous state
	}
	li.push_front(n);
	find_solution(t-n, n-1);
	li.pop_front();
	find_solution(t, n-1);

}


int main()
{
	int T = 20;
	int N = 20;

	find_solution<int>(T,N);
	cout << "there are "<< count << " combinations" << endl;

	return 0;
}
