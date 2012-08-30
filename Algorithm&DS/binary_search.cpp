/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-30 18:54:01
desc: binary search from the aocp
*/

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

template <class type>
type random(type start, type end)
{
	srand((unsigned)time(0)*rand());
	return (start + (end-start)*rand()/(RAND_MAX+1.0));
}

int main()
{
	return 0;
}