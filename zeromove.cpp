 /*
 *discription:给定一组数，将零全部排到最后，将非零元素排在最前,华为面试
 *autor:justinzhang
 *Email:uestczhangchao@gmail.com
 *Established:2011年2月8日21:13:47
 *Revised1:2011年4月24日15:57:22 
 *Revised2:2011年5月10日15:21:54,受到算法导论快速排序的启发，(p85)
 *								利用快速排序中用来寻找支点的算法来完成任务
 */
 
 
 #include <iostream>
 using namespace std;
 #define arraysize(type, name) (sizeof(name) / sizeof(type))
 
 
 /*http://www.iteye.com/topic/684511 这个帖子是讲如何将0元素移动到最前面，非零元素移动到最后面的*/
 
 /*
 *nonezerofirst()和zerofirst()采用了不同的思想，具体参见源代码了. 
 *
 */
 

 /* 打印数组里的元素*/
 void display(int data[], int len)
 {
	 for(int i=0; i<len; i++)
		 cout << data[i] << endl;
 }

 /*用算法导论中快速排序算法找支点的思想来完成将0元素集中到最前面
 *使用这个思想可以解决把具有某一性质（0，非零，负数，正数等等）
 *的元素移动到数组的末尾或者最前面的问题
 */

void quickmove_zerofirst(int data[], int len)
{
	int i = -1;
	
	/*data中元素下标从0开始，故倒数第1个元素的下标为len-1;
	*从左向右扫描数组，如果发现0就与最前边由i记录的位置处元素交换
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


/*用算法导论中快速排序算法找支点的思想来完成将0元素集中到最后面*/
void quickmove_zerolast(int data[], int len)
{
	//data中元素下标从0开始，故倒数第1个元素下一个元素为len，
	//此处为刚好为数组越界的位置，这样做主要是为了方便循环的处理的统一
	//i记录的是最右边0元素序列的最左边位置
	int i=len;
	for(int j=len-1; j>=0;j--)
	{
		//如果在扫描过程中发现了0元素，就把它交换到数组右边0元素序列的最左边
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
 *该函数将0元素移动到数据的最前面，非零元素移动到队列的最后面。 
 *实现方法是：从数组的最后一个元素向前扫描，记住非零元素串最右边的位置，
 *程序中用high来表示，结束扫描的时候[0,high]之间的数全部清零就可以完成任务。 
 */
 void zerofirst(int data[], int len)
 {
      //自右向左扫描，将所有非零元素紧凑到右侧  
      int low, high;
      for(low = len -1,high = low; low >=0; low--)
      {
              if(data[low]!=0)
              {
                   data[high] = data[low];
                   high--;//更新紧凑序列的最左侧元素   
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
    //自左向右扫描，将非零元素紧凑到最左边 
    int j = 0;
    for (int i = 0; i < len; i++) { 
        //加入下面的判断是为了记录下非零元素串最右边的位置 
        if(data[i] != 0)
                j++; //更新紧凑序列最右边的元素位置 
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
