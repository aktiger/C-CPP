/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-30 18:54:01
desc: binary search from the aocp p380
*/

#include <iostream>
#include <vector>
#include <memory> //for auto_ptr, but auto_ptr does not support arrays
#include <ctime> // for time(0) function
#include <cstdlib> // for srand and rand function
#include <algorithm> // for sort and binary_search function
using namespace std;

template <class type>
type random(type start, type end)
{
	srand((int)time(0)*rand());
	return (start + (end-start)*rand()/(RAND_MAX+1.0));
}

template<class type> bool my_binary_search(vector<type> data, int begin, int end, type value)
{
	int L = begin;
	int U = end;
	while(U>L) //注意此处不要写成了U>=L,如果是>=，并且数组下标从0开始的话，就会导致vector下标越界
	{
		int M = L+(U-L)/2;
		if(data[M] > value)
			U = M-1;
		else if(data[M] < value)
			L = M+1;
		else
			return true;
	}
	return false;
}

template <class type> bool recursive_binary_search(vector<type> data, int begin, int end, type key)
{
	if(begin >= end)
		return false;
	else
	{
		int mid = begin+(end - begin)/2;
		if(data[mid] > key)
			recursive_binary_search(data,begin,mid-1,key);
		else if(data[mid] < key)
			recursive_binary_search(data,mid+1,end,key);
		else
			return true;
	}
}


int main()
{
	/*auto_ptr does not support for arrays, C11 support*/
	//auto_ptr<double> auto_ptr_data(new double);
	//*auto_ptr_data = 100;
	//cout << *auto_ptr_data << endl;
	
	vector<double> data;
	for(unsigned int i=0; i<20; i++)
	{
		data.push_back(random<double>(1,10));
	}
	
	data.push_back(77.77);
	
	vector<double> copy_data(data.size());
	copy(data.begin(),data.end(),copy_data.begin());

	for(unsigned int i=0; i<10; i++)
	{
		cout << data[i] << "==" << copy_data[i] << endl;
	}

	sort(data.begin(),data.end());
	for(unsigned int i=0; i<data.size(); i++)
	if(binary_search(data.begin(),data.end(),copy_data[i]))
	{
		cout << "found item: " << copy_data[i] << endl;
	}
	
	/*-----test non-recursive version-----*/
	if(my_binary_search<double>(data,0,data.size(),898))
	{
		cout << " find item: " << 898<< endl;
	}
	else
		cout << "not found item:" << 898 << endl;
	
	/*----test recursive binary search-----*/
	vector<double> A(10,random(1,10)); //初始化向量A，每一个元素都为1
	for(int i=0; i<10; i++)
		cout << A[i] << endl;
	if(recursive_binary_search<double>(A,1,5,1))
		cout << "found !" << endl;

	
	return 0;
}















