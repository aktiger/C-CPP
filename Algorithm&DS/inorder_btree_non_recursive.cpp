/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-20 15:52:27
des.:using non recursive method to traverse binary tree
*/
#include <iostream>
#include <ctime>
using namespace std;

template<typename T> class btree
{
public:
	T data;
	btree *lchild, *rchild;
};

/*	create binary tree, with one parameter.
	the binary tree is inputed through pre order,
	1
   2 3, is input as 1 2 -1 -1 3 -1 -1,(-1 represent nil node);
*/
btree<double> * create_btr(btree<double> **root)
{
	double data ;
	cin>>data;
	/* -1.0 represent the nil node */
	if(data == -1.0) 
	{
		*root=NULL;
	}
	else
	{
		*root = new btree<double>();
		(*root)->data = data;
		(*root)->lchild = create_btr(&(*root)->lchild);
		(*root)->rchild = create_btr(&(*root)->rchild);		
	}
	return *root;
}

/*create binary tree without parameter!*/
btree<double>* create_btr()
{
	double data;
	cin >> data;
	if(data == -1)
		return NULL; //return nill node
	else
	{
		btree<double> *T = new btree<double>;
		T->data = data;
		T->lchild = create_btr();
		T->rchild = create_btr();
		return T;
	}
}

void inorder(btree<double> *r)
{
	if(NULL==r)
		return;
	inorder(r->lchild);
	cout << r->data<<endl;
	inorder(r->rchild);
}

int main()
{
	btree<double> *root = NULL;
	create_btr(&root);
	btree<double> *T = create_btr();
	inorder(root);
	inorder(T);
	return 0;
}