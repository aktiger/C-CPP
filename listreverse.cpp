/*
*about: 腾讯面试，将一个单向链表逆序
*author:justinzhang
*email:uestczhangchao@gmail.com
*estblished:2011年4月24日16:40:25
*revised:2011年5月10日15:00:26
*/

#include <iostream>
using namespace std;

class node
{
      public:
      node * next;
      int data;
};


node *test = NULL;

node *nodereverse(node *head)
{
	//如果一个函数的输入参数有指针，一定要记住判断指针时候为空
	//1>:在使用一个指针之前一定要判断它是否为空;
	//2>:使用完后要释放由指针指向的存储单元
	//3>:释放完存储单元后要将指针赋值为NULL;
     if(head->next==NULL || head==NULL)
          return head;

     node* temp1=head;
     node* temp2=NULL;
     node* temp3=head->next;
	 temp1->next = NULL;
	 //要注意这里面的顺序,先将temp3保存在temp2中，
	 //然后再将temp3移动到下一个元素，然后才能改动temp2
	 //
     while(temp3->next!=NULL)
     {
	    temp2 = temp3;
		temp3 = temp3->next;
		temp2->next = temp1;//不能再temp3= temp3->next;之前执行
		temp1 = temp2;

     }
     temp3->next = temp2;
     return temp3;
}
void initnode()
{
     node * tmp = NULL;
     for(int i=0; i<4; i++)
     {
		 tmp = new node;
         tmp->data = i;
         tmp->next = test;
         test = tmp;
     }
}

void display(node *nn)
{
if(nn==NULL)
{
	cout << "no data to display\n";
	return ;
}
node *dis = nn;
 while(dis!=NULL)
 {
        cout << dis->data << endl;
        dis = dis->next;
 }
}

//释放动态申请的空间
void distroy(node *nn)
{
	if (nn==NULL)
	{
		return ;
	}
	while (nn!=NULL)
	{
		node *tmp = nn;
		nn = nn->next;
		delete tmp;
	}
}


int main()
{
    initnode();
    display(test);
    cout << "**************" << endl;
    node *tmp = nodereverse(test);
	if(test==NULL)
		exit(0);
    display(tmp);
	//tmp和test指向的存储空间已经使用完毕，应该释放掉他们申请的空间！
	//并且，要将他们赋值为NULL，否则他们将成为野指针！！！！，一定要注意了~~
	distroy(tmp);//释放动态申请的内存
	tmp = NULL;//将他们重新赋值为NULL，不然就会成为野指针~~~~~
	test = NULL;
	cout << "tmp= " << tmp << endl;

	//如果上面没有tmp = NULL;test = NULL;，display将会出错，
	//因为在display开始的时候判断传入的参数是否为NULL，如果不把野指针赋值为NULL，
	//那么判断就没有效果，会继续指向display中的while语句，而此时指针所指向的存储空间已经被释放掉了，
	//这样就会出现异常.
	display(test);
    system("pause");
    return 0;
}
