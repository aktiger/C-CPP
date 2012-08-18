 /*
 *discription:����һ����������ȫ���ŵ���󣬽�����Ԫ��������ǰ,��Ϊ����
 *autor:justinzhang
 *Email:uestczhangchao@gmail.com
 *Established:2011��2��8��21:13:47
 *Revised1:2011��4��24��15:57:22 
 *Revised2:2011��5��10��15:21:54,�ܵ��㷨���ۿ��������������(p85)
 *								���ÿ�������������Ѱ��֧����㷨���������
 */
 
 
 #include <iostream>
 using namespace std;
 #define arraysize(type, name) (sizeof(name) / sizeof(type))
 
 
 /*http://www.iteye.com/topic/684511 ��������ǽ���ν�0Ԫ���ƶ�����ǰ�棬����Ԫ���ƶ���������*/
 
 /*
 *nonezerofirst()��zerofirst()�����˲�ͬ��˼�룬����μ�Դ������. 
 *
 */
 

 /* ��ӡ�������Ԫ��*/
 void display(int data[], int len)
 {
	 for(int i=0; i<len; i++)
		 cout << data[i] << endl;
 }

 /*���㷨�����п��������㷨��֧���˼������ɽ�0Ԫ�ؼ��е���ǰ��
 *ʹ�����˼����Խ���Ѿ���ĳһ���ʣ�0�����㣬�����������ȵȣ�
 *��Ԫ���ƶ��������ĩβ������ǰ�������
 */

void quickmove_zerofirst(int data[], int len)
{
	int i = -1;
	
	/*data��Ԫ���±��0��ʼ���ʵ�����1��Ԫ�ص��±�Ϊlen-1;
	*��������ɨ�����飬�������0������ǰ����i��¼��λ�ô�Ԫ�ؽ���
	*/
	for(int j=0; j<=len-1;j++)
	{
		if(data[j]==0)
		{
			i++;
			data[j] = data[i];
			data[i] = 0;
		}
	}
	cout << "in quickmove_zerofirst" << endl;
	 display(data,len);
	 cout << "end of quickmove_zerofirst" << endl;
}


/*���㷨�����п��������㷨��֧���˼������ɽ�0Ԫ�ؼ��е������*/
void quickmove_zerolast(int data[], int len)
{
	//data��Ԫ���±��0��ʼ���ʵ�����1��Ԫ����һ��Ԫ��Ϊlen��
	//�˴�Ϊ�պ�Ϊ����Խ���λ�ã���������Ҫ��Ϊ�˷���ѭ���Ĵ����ͳһ
	//i��¼�������ұ�0Ԫ�����е������λ��
	int i=len;
	for(int j=len-1; j>=0;j--)
	{
		//�����ɨ������з�����0Ԫ�أ��Ͱ��������������ұ�0Ԫ�����е������
		if(data[j]==0)
		{
			i = i-1;
			data[j] = data[i];
			data[i] = 0;
		}
	}
	cout << "in quickmov_zerolast" << endl;
	display(data,len);
	cout << "end of quickmov_zerolast" <<endl;
}


 
 
 /*
 *�ú�����0Ԫ���ƶ������ݵ���ǰ�棬����Ԫ���ƶ������е�����档 
 *ʵ�ַ����ǣ�����������һ��Ԫ����ǰɨ�裬��ס����Ԫ�ش����ұߵ�λ�ã�
 *��������high����ʾ������ɨ���ʱ��[0,high]֮�����ȫ������Ϳ���������� 
 */
 void zerofirst(int data[], int len)
 {
      //��������ɨ�裬�����з���Ԫ�ؽ��յ��Ҳ�  
      int low, high;
      for(low = len -1,high = low; low >=0; low--)
      {
              if(data[low]!=0)
              {
                   data[high] = data[low];
                   high--;//���½������е������Ԫ��   
              }
      } 
      
      for(;high>=0; high--)
      {
          data[high] = 0;
      }
      cout << "in zero first" << endl;
       display(data, len);
	   cout << "end of zero first" << endl;
      
 } 
 
 void nonzerofirst(int data[], int len)
 {
    //��������ɨ�裬������Ԫ�ؽ��յ������ 
    int j = 0;
    for (int i = 0; i < len; i++) { 
        //����������ж���Ϊ�˼�¼�·���Ԫ�ش����ұߵ�λ�� 
        if(data[i] != 0)
                j++; //���½����������ұߵ�Ԫ��λ�� 
        if (data[i] == 0 && i != len - 1 && data[i + 1] != 0) {   
            data[j++] = data[i + 1];   
            data[i + 1] = 0;   
        }   
    }   
    cout << "non zero first " << endl;
    display(data, len);
	cout << "end of non zero first " << endl;
 }

 int main()
 {
 int a[] = { 4,4,0, 4, -7, 2, 160, 0,0,0,0, 34, 21, 0, 19, 107 };   
 int j = 0;   
 int tmp = arraysize(int, a);
 cout << sizeof(a) << endl; 
 cout << "sizeof(a)" << tmp << endl;
 quickmove_zerofirst(a,tmp);
 quickmove_zerolast(a,tmp);

 zerofirst(a, tmp);
 nonzerofirst(a, tmp); 
 system("pause");
}
