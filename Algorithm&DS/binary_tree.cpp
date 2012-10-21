/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-20 15:52:27
des.:using non recursive method to traverse binary tree

rev: 2012-10-21 11:27:26 
    	Added:
	 1. layered_order;
	 2. predored_nonrecursive
	 3. inoder_nonrecursive
	 4. postorder_nonrecursive
	 5. rebuild_pre_in
	 6. rebuild_post_in
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

template<class T> void preorder(btree<T> *r)
{
	if(r==NULL)
		return;
	cout << r->data << " ";
	preorder(r->lchild);
	preorder(r->rchild);
}

void inorder(btree<double> *r)
{
	if(NULL==r)
		return;
	inorder(r->lchild);
	cout << r->data<< " ";
	inorder(r->rchild);
}
void postorder(btree<double> *r)
{
	if(NULL==r)
		return ;
	postorder(r->lchild);
	postorder(r->rchild);
	cout << r->data<<" ";
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
		cout << node->data << " ";
		if(node->lchild != NULL)
			Q.push_back(node->lchild);
		if(node->rchild != NULL)
			Q.push_back(node->rchild);
		Q.pop_front();
	}
	cout << endl;
}

template<class T> void preorder_nonrecursive(btree<T> *r)
{
	if(NULL == r)
		return ;
	btree<T>* node = r;
	deque<btree<T> *> stack;

	while(!stack.empty() || node!=NULL)
	{
		while(node)
		{
			cout << node->data << " ";
			stack.push_back(node);
			node = node->lchild;
		}
		node = stack.back();
		stack.pop_back();
		node = node->rchild;
	}
	cout << endl;
}



template<class T> void inodre_nonrecursive(btree<T> * root)
{
	if(NULL == root)
		return;
	btree<T> * node = NULL;
	deque<btree<T> *> stack;
	node = root;
	while(!stack.empty() || node!=NULL)
	{
		while(node)
		{
			stack.push_back(node);
			node = node->lchild;
		}
		node = stack.back();
		stack.pop_back();
		cout << node->data <<" ";
		node = node->rchild;
	}
	cout << endl;

}

template<class T> void postorder_nonrecursive(btree<T> *r)
{
	if(r==NULL)
		return ;
	deque<btree<T> *> stack;
	deque<int> stack_flag;
	int flag = 0;
	btree<T> * node = r;
	stack.push_back(r);
	stack_flag.push_back(1);

	while(!stack.empty())
	{
		while(node && node->lchild)
		{
			stack.push_back(node->lchild);
			stack_flag.push_back(1);
			node = node->lchild;
		}

		node = stack.back();
		flag = stack_flag.back();
		stack.pop_back();
		stack_flag.pop_back();

		if(flag == 1)
		{
			stack.push_back(node);
			stack_flag.push_back(2);
			node = node->rchild;
			if(node)
			{
				stack.push_back(node);
				stack_flag.push_back(1);
			}
		}
		else
		{
			cout << node->data <<" ";
			node = NULL;
		}
	}
	cout << endl;
}

/*----To reconstruct a binary tree from the inorder and preorder;2012-10-21 16:48:54-----*/
template<class T> void rebuild_pre_in(T preorder[], size_t lp, size_t rp, T middle[], size_t lm, size_t rm , btree<T> **root)
{
	/*
	if the size of preorder and inorder is not equal,or the size of order is zero,
	there must be errors, so returns
	*/
	if((rp-lp) != (rm-lm) || (rp-lp+1)==0)
		return;
	
	*root = new btree<T>();
	(*root)->data = preorder[lp];
	
	size_t m = lm;
	while(preorder[lp] != middle[m])
	{
		m++;
	}

	if(m==lm)
		(*root)->lchild = NULL;
	else 
		rebuild_pre_in(preorder, lp+1, lp+m-lm, middle, lm, m-1, &(*root)->lchild);
	if(m == rm)
		(*root)->rchild = NULL;
	else
		rebuild_pre_in(preorder, lp+m-lm+1, rp, middle, m+1, rm, &(*root)->rchild);
}

/*
	To construct binary tree from postorder and inorder; 2012-10-21 20:25:23
	To get the right boundary, you can get a small binary tree and generalize it;
*/
template<class T> void rebulid_post_in(T post[], size_t lp, size_t rp, T middle[], size_t lm, size_t rm, btree<T> **root)
{
	if((rp-lp)!=(rm-lm) || (rp-lp+1)==0)
		return;
	(*root)= new btree<T>();
	(*root)->data = post[rp];
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;

	size_t m = lm;
	while(post[rp] != middle[m])
	{
		m++;
	}
	size_t len = m - lm;
	if(m==lm)
		(*root)->lchild = NULL;
	else
		rebulid_post_in(post, lp, lp+len-1, middle, lm, m-1, &(*root)->lchild);
	if(m==rm)
		(*root)->rchild = NULL;
	else
		rebulid_post_in(post, lp+len, rp-1, middle, m+1, rm, &(*root)->rchild);
}

int main()
{
	/*
	test binary tree:1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
					you can see the binary tree from layered_order easily~~
	*/
	btree<double> *root = NULL;
	create_btr(&root);
	//btree<double> *T = create_btr();
	cout << "preoredr:" << endl;
	preorder(root); cout << endl;
	cout << "inorder:" << endl;
	inorder(root);	cout << endl;
	cout << "postorder:"<< endl;
	postorder(root); cout << endl;
	//inorder(T);

	cout << "layered order:" << endl;
	layered_order<double>(root);


	cout << "preorder_nonrecursive:" << endl;
	preorder_nonrecursive<double>(root);

	cout << "inorder_nonrecursive:" << endl;
	inodre_nonrecursive<double>(root);

	cout << "postorder_nonrecursive:" << endl;
	postorder_nonrecursive<double>(root);

	/*
	pay attention that if you give the rebuild function the wrong tranverse sequence ,
	the program will in erro..., so your preorder and inorder must from the same tree,
	you should not cheat the program.
	*/
	cout << "reconstruct binary tree from preorder and inorder!" << endl;
	char pre[] = "abcdefghi";
	char inorder[] = "bcaedghfi";
	char post[] = "cbehgifda";

	btree<char> * recovery_tree = NULL;
	btree<char> * recovery_tree2 = NULL;
	rebuild_pre_in<char> (pre, 0, strlen(pre)-1, inorder, 0, strlen(inorder)-1, &recovery_tree);
	postorder_nonrecursive<char>(recovery_tree);

	cout <<"reconstruct binary tree from postorder and inorder!" << endl;
	rebulid_post_in<char> (post, 0, strlen(post)-1, inorder, 0, strlen(inorder)-1, &recovery_tree2);
	postorder_nonrecursive<char>(recovery_tree2);
	preorder<char>(recovery_tree2);

	return 0;
}