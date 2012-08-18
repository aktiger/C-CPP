/*
*about: ��Ѷ���ԣ���һ��������������
*author:justinzhang
*email:uestczhangchao@gmail.com
*estblished:2011��4��24��16:40:25
*revised:2011��5��10��15:00:26
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
	//���һ�����������������ָ�룬һ��Ҫ��ס�ж�ָ��ʱ��Ϊ��
	//1>:��ʹ��һ��ָ��֮ǰһ��Ҫ�ж����Ƿ�Ϊ��;
	//2>:ʹ�����Ҫ�ͷ���ָ��ָ��Ĵ洢��Ԫ
	//3>:�ͷ���洢��Ԫ��Ҫ��ָ�븳ֵΪNULL;
     if(head->next==NULL || head==NULL)
          return head;

     node* temp1=head;
     node* temp2=NULL;
     node* temp3=head->next;
	 temp1->next = NULL;
	 //Ҫע���������˳��,�Ƚ�temp3������temp2�У�
	 //Ȼ���ٽ�temp3�ƶ�����һ��Ԫ�أ�Ȼ����ܸĶ�temp2
	 //
     while(temp3->next!=NULL)
     {
	    temp2 = temp3;
		temp3 = temp3->next;
		temp2->next = temp1;//������temp3= temp3->next;֮ǰִ��
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

//�ͷŶ�̬����Ŀռ�
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
	//tmp��testָ��Ĵ洢�ռ��Ѿ�ʹ����ϣ�Ӧ���ͷŵ���������Ŀռ䣡
	//���ң�Ҫ�����Ǹ�ֵΪNULL���������ǽ���ΪҰָ�룡��������һ��Ҫע����~~
	distroy(tmp);//�ͷŶ�̬������ڴ�
	tmp = NULL;//���������¸�ֵΪNULL����Ȼ�ͻ��ΪҰָ��~~~~~
	test = NULL;
	cout << "tmp= " << tmp << endl;

	//�������û��tmp = NULL;test = NULL;��display�������
	//��Ϊ��display��ʼ��ʱ���жϴ���Ĳ����Ƿ�ΪNULL���������Ұָ�븳ֵΪNULL��
	//��ô�жϾ�û��Ч���������ָ��display�е�while��䣬����ʱָ����ָ��Ĵ洢�ռ��Ѿ����ͷŵ��ˣ�
	//�����ͻ�����쳣.
	display(test);
    system("pause");
    return 0;
}
