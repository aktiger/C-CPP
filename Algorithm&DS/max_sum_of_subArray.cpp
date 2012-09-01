/*
@@
	Author:	Justinzhang
	Email:	uestczhangchao@gmail.com
	time:	2012-9-1 21:40:13
	desc:	find the max sum of sub arrys; This file was created at an earlier time; 
			At that time, i didn't read the programming perls, in that book, there is a detailed
			discussion about this problem. The fastest algrithm can solve it in O(n) time;
			So if have spare time, read more of it.
@@
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template<class type> 
type getMax(type param1, type param2)
{
	return (param1>param2 ? param1 : param2);
}

template<class type> type find_max_sum_of_subarray(vector<type> vec)
{
	type maxSum = 0;
	type curMaxSum = 0;
	for(unsigned int i=0; i < vec.size(); i++)
	{
		curMaxSum += vec[i];
		curMaxSum = getMax(0, curMaxSum);
		maxSum = getMax(maxSum, curMaxSum);
	}
	return maxSum;
}


int main()
{
	int array[] = {-2, 5, 3,-6, 44, -8, 16};
	/* /!\ note that: to use array to initialize vector, the second parameter is the length of array,
	   not the length of array minus 1.
	*/
	vector<int> vec(array,array+(sizeof array / sizeof(int)));
	cout << "find_max_sum_of_subArray: " << find_max_sum_of_subarray<int>(vec) << endl;
	return 0;
}