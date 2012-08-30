/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-30 18:54:01
desc: binary search from the aocp
*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

template <class type>
type random(type start, type end)
{
	srand((int)time(0)*rand());
	return (start + (end-start)*rand()/(RAND_MAX+1.0));
}

int main()
{
	
	auto_ptr<double> data(new double[20]);
	int i = 0;
	for(int i=0; i<20; i++)
	{
		data[i] = random<double>(1.0,20.0);	
	}
	return 0;
}















