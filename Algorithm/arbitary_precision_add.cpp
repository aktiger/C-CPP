/*
Author:JustinZhang
Email:uestczhangchao@gmail.com
Time:2012年4月22日23:39:40
desc:高精度加法
*/

#include <iostream>
#include <cstring>
using namespace std;

/*
a、b为字符数组，内部存储了加数和被加数，ans用来存放最终结果，也为字符数组
*/
void arbitary_add(const char *a, const char *b,char *ans)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int maxlen = (lena > lenb) ? lena : lenb; //求得两个串长的最大者
	int *arrayA = new int [maxlen+1];
	int *arrayB = new int [maxlen+1];
	
	int *intans = new int [maxlen+1];//用来存放两个字符串的数字相加的结果
	int i=0,j=0;

	//对加法的结果数组清零
	for(i=0; i<maxlen+1; i++)
	{
		intans[i] = 0;
		arrayA[i] = 0;
		arrayB[i] = 0;
	}

	//将加数字符串中的数组取出来，放到整型数组当中，字符数组的第一个字符对应于整数的最高位.
	for(i=0; i<lena; i++)
	{
		arrayA[lena-i-1] = a[i] - '0';
	}
	//将被加数字符串中的数组取出来，放到整型数组当中，字符数组的第一个字符对应于整数的最高位.
	for(j=0; j<lenb; j++)
	{
		arrayB[lenb-j-1] = b[j] - '0';
	}
	//根据上面得到的整型数组，一位一位的做加法操作
	for(i=0; i<maxlen; i++)
	{
		intans[i] += arrayA[i]+ arrayB[i];
		
		//如果第i位的结果超过10，那么就向第i+1位进位
		if(intans[i] > 9)
		{
			intans[i] = intans[i] - 10;
			intans[i+1] = intans[i+1] + 1;
		}
	}

	//如果最高位有进位
	if(intans[maxlen]!=0)
	{
		ans[0] = intans[maxlen]+'0';
		//将整型数组转换为字符数组
		for(i=1; i<=maxlen;i++)
		{
			ans[i] = intans[maxlen-i]+'0';
		}
		ans[maxlen+1] = '\0';
	}
	else
	{
		//将整型数组转换为字符数组
		for(i=0; i<maxlen;i++)
		{
			ans[i] = intans[maxlen-i-1]+'0';
		}
		ans[maxlen] = '\0';
	}
	delete [] arrayA;
	delete [] arrayB;
	delete [] intans;
}

int main()
{
	int count = 0;
	char *ans = new char[20];
	char *s1 = "1239945";
	char *s2 = "79999999";
	arbitary_add(s1,s2,ans);
	while(ans[count]!='\0')
	{
		cout << ans[count++] ;
	}
	cout << endl;
	delete [] ans;
	return 0;
}