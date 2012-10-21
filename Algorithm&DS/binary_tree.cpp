/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-20 15:52:27
des.:using non recursive method to traverse binary tree

rev: 2012-10-21 11:27:26 
    	Added:
	 1. layered_order;
	 2. predored_nonrecursive
*/
#include <iostream>
#include <deque>
#include <stack>
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

void preorder(btree<double> *r)
{
	if(r==NULL)
		return;
	cout << r->data << endl;
	preorder(r->lchild);
	preorder(r->rchild);
}

void inorder(btree<double> *r)
{
	if(NULL==r)
		return;
	inorder(r->lchild);
	cout << r->data<<endl;
	inorder(r->rchild);
}
void postorder(btree<double> *r)
{
	if(NULL==r)
		return ;
	postorder(r->lchild);
	postorder(r->rchild);
	cout << r->data<<endl;
}

template<class T> void layered_order(btree<T> *r)
{
	if(NULL==r)
	{
		return;
	}
	btree<T>* node = NULL;
	deque<btree<T>* > Q;
	Q.push_back(r);
	while(!Q.empty())
	{
		node = Q.front();
		cout << node->data << endl;
		if(node->lchild != NULL)
			Q.push_back(node->lchild);
		if(node->rchild != NULL)
			Q.push_back(node->rchild);
		Q.pop_front();
	}
}

template<class T> void preorder_nonrecursive(btree<T> *r)
{
	if(NULL == r)
		return ;
	btree<T>* node = r;
	deque<btree<T> *> stack;
	cout << node->data << endl;
	stack.push_back(node);
	while(!stack.empty())
	{
		while(node->lchild != NULL)
		{
			cout << node->lchild->data << endl;
			stack.push_back(node->lchild);
			node = node->lchild;
		}
		node = stack.back();
		stack.pop_back();
		if(node->rchild != NULL)
		{
			stack.push_back(node->rchild);
			node = node->rchild;
			cout << node->data << endl;
		}
		
	}
}


int main()
{
	btree<double> *root = NULL;
	create_btr(&root);
	//btree<double> *T = create_btr();
	cout << "preoredr:" << endl;
	preorder(root);
	cout << "inorder:" << endl;
	inorder(root);
	cout << "postorder:"<< endl;
	postorder(root);
	//inorder(T);

	cout << "layered order:" << endl;
	layered_order<double>(root);


	cout << "preorder_nonrecursive:" << endl;
	preorder_nonrecursive<double>(root);


	return 0;
}