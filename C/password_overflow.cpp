
/*
*This program demonstrate how the stack is overflow,in this case the password filed is 
*override by user input.even though the user don't konow password,he can still get into the system.
*�ó�����vs2008��debug�汾�л��������������release�в��ܳ�����������.
*ʱ�䣺2011��8��18��17:44:33
*���ߣ��ų�
*Email:uestczhangchao@gmail.com
*/


//#include "X:\�����ϰ\C-C++\global.h"

//#if password_overflow==stdon

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
int main()
{
	/*password��input��˳���ܹ��ߵ�����Ϊ�ֲ���������ջ�ϰ��ն���˳��
	�Ӹߵ�ַ���ص�ַ�ݼ�����&password[0]>&input[0]������ÿ�����飬����Ԫ�ؿ�ʼ��
	���ε����Ĵ�ţ���&password[1]>&password[0]��ֻ����������ſ�����input����������ʱ��
	���ǵ�password�����ݡ�
	*/
	char password[10]="123456789";
	char input[10];

	int i;
	cout<<"����������"<<endl;
	cin>>input;
	for(i=0;i<10;i++)
	{
		if(password[i]!=input[i])
			break;
	}

	/*������strcmp�ǲ��еģ���Ϊinput�Լ��Ѿ������ĩβ��\0�Ѿ����滻��1�ˣ�
	ͬʱpasswordĩβ��\0Ҳ�Ѿ����滻��1�ˡ���strcmp������\0���ж��ַ�����β��*/
	if(i==10)
	{
		cout<<"������ȷ"<<endl;
	}
	else
	{
		cout<<"�������"<<endl;
	}
	system("pause");
	return 0;
}
//#endif