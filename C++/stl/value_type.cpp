/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-23 10:28:53
desc: value_type , from <the annotated stl source>, chapter 3, p86
iterator_traits will be coflict with system, so i use another name.
*/
#include<iostream>
using namespace std;

template <class T>
struct MyIter
{
	typedef T value_type;
	T* ptr;
	MyIter(T* p=0) : ptr(p){}
	T& operator*() const {return *ptr;}
	
};
template <class I>
struct iterator_traitss
{
	typedef typename I::value_type value_type;	
};

template <class T>
struct iterator_traitss<T*>
{
	typedef T value_type;
};

template <class I>
typename iterator_traitss<I>::value_type
func(I ite)
{
	return *ite;
}

int main()
{
MyIter<int> ite(new int(8));
cout << func(ite)<<endl;
return 0;
} 
