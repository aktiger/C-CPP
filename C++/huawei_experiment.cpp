/**
*Author:	Justinzhang
*Email:		uestczhangchao@gmail.com
*Time:		2012-9-16 10:41:47
*Desc:		from yesterday's computer practice, i didn't solve the third problem;	
*
**/

/* 请在这里实现下列函数, c/c++语法不限, 最后需要保证程序编译连接通过, 并生成test.exe文件. */
/* 相关宏定义及函数声明见'func.h'头文件 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;


/* 问题1,删除重复字符 */
int  DelChar(char* input, char *output)
{
	if(input==NULL)
	{
		if(output==NULL)
			return 0;
		else
		{
			*output = '\0';
			return 0;
		}
	}
	int i=0, j=0, count=0;
	int len = strlen(input);
	for (i=0; i<len; i++)
	{
		for(j=0; j<i; j++)
		{
			if (input[i] == input[j])
			{
				break;
			}
		}
		if (j==i)
		{
			output[count++] = input[i];
		}
	}
	output[count] = '\0';
	return 0;
}

/*here i want to use hash table to make it more faster, at the cost of const extra space*/
int  DelChar2(char* input, char *output)
{
	if(input==NULL)
	{
		if(output == NULL)
		{
			return 0;
		}
		else
		{
			*output = '\0';
			return 0;
		}
	}
	/*there are at most 128 ansi charactors*/
	int hash[256];
	int i=0;
	int j=0;
	memset(hash, 0, sizeof(int)*256);
	while(input[i] != '\0')
	{
		if(hash[input[i]]==0)
		{
			hash[input[i]] = 1;
			output[j++] = input[i];
		}
		i++;
	}
	output[j] = '\0';
	return 0;
}



/* 问题2,车牌限行 */
int CalculateLimitingCarCard(char *pCarCard,int dwDate, char *pLimitCarCard)
{
	if(pCarCard==NULL)
	{
		if(pLimitCarCard==NULL)
			return 0;
		else
		{
			*pLimitCarCard = '\0';
			return 0;
		}
	}
	if (dwDate<0 || dwDate>6)
	{
		*pLimitCarCard='\0';
		return -1;
	}

	if (dwDate==0 || dwDate==6)
	{
		*pLimitCarCard = '\0';
		return 0;
	}
	
	int len = strlen(pCarCard);
	int i=0, j=0, k=0, l=0;
	int count = 0;
	char *tmp = pCarCard;
	char carnum[6];
	int index_limint = 0;
	for (i=0; i<len; i++)
	{
		if (isalnum(pCarCard[i]) || pCarCard[i]==',' )
		{
			continue;
		}
	}
	if (i!=len)
	{
		*pLimitCarCard='\0';
		return -1;
	}
	
	while (*pCarCard != '\0')
	{
		j=0;
		while((*pCarCard !=',')&&(*pCarCard!='\0'))
		{
			carnum[j++] = *pCarCard++;
		}
		if(j>5)
		{
			*pLimitCarCard='\0';
			return -1;
		}

		pCarCard++;
		
		for (k=4; k>=0; k--)
		{
			if (isalpha(carnum[k]))
			{
				count++;
			}
		}

		if (count==5) //all charactors
		{
			*pLimitCarCard='\0';
			return -1;
		}

		for (k=4; k>=0; k--)
		{

			if (dwDate==1)
			{
				if ((carnum[k]-'0')==1 || (carnum[k]-'0')==6)
				{
					for (l=0; l<=4; l++)
					{
						pLimitCarCard[index_limint++] = carnum[l];
					}
					pLimitCarCard[index_limint++]=',';
					break;
				}
			}
			else if (dwDate==2)
			{
				if ((carnum[k]-'0')==2 || (carnum[k]-'0')==7)
				{
					for (l=0; l<=4; l++)
					{
						pLimitCarCard[index_limint++] = carnum[l];
					}
					pLimitCarCard[index_limint++]=',';
					break;
				}
				
			}
			else if (dwDate == 3)
			{
				if ((carnum[k]-'0')==3 || (carnum[k]-'0')==8)
				{
					for (l=0; l<=4; l++)
					{
						pLimitCarCard[index_limint++] = carnum[l];
					}
					pLimitCarCard[index_limint++]=',';
					break;
				}
			}
			else if (dwDate == 4)
			{
				if ((carnum[k]-'0')==4 || (carnum[k]-'0')==9)
				{
					for (l=0; l<=4; l++)
					{
						pLimitCarCard[index_limint++] = carnum[l];
					}
					pLimitCarCard[index_limint++]=',';
					break;
				}
			}
			else //here process friday 
			{
				if ((carnum[k]-'0')==5 || (carnum[k]-'0')==0)
				{
					for (l=0; l<=4; l++)
					{
						pLimitCarCard[index_limint++] = carnum[l];
					}
					pLimitCarCard[index_limint++]=',';
					break;
				}	
			}
			
		if (carnum[k]>='0' && carnum[k]<='9')
		{
			break;
		}
			
		}// end 	for (k=4; k>=0; k--)

	}// end 	while (*pCarCard != '\0')


	if (index_limint!=0)
	{
		pLimitCarCard[index_limint-1]='\0';
	}
	else
	{
		pLimitCarCard[index_limint]='\0';
	}
	
	return 0;
}

typedef struct {
	char str[64];
	int  origin_pos;
	int  match_pos;
	int len;
}Tword;

/* 问题3,多单词匹配 */
int MultiWordMatch(char *Src, char *Match)
{	
	int i=0, j=0;
	int count_source = 0;
	int count_match = 0;
	int word_len_origin = 0;
	int word_pos_origin = 0;
	int word_len_match = 0;
	int word_pos_match = 0;

	Tword word_origin[64]; 
	Tword word_match[64];
	/* initialize struct */
	for(i=0; i<64; i++)
	{
		word_origin[i].len = 0;
		word_match[i].len = 0;

		word_origin[i].origin_pos = -2;
		word_match[i].origin_pos = -2;

		word_origin[i].match_pos = -1;
		word_match[i].match_pos = -1;

		memset(word_origin[i].str, 0, sizeof(word_origin[i].str));
		memset(word_match[i].str, 0, sizeof(word_match[i].str));
	}
	
	while(*Src != '\0')
	{
		j=0;
		word_len_origin = 0;
		while (*Src!=' ' && *Src!='\0') //here we must add *Src!='\0' condition
		{
			word_origin[count_source].str[j++] = tolower(*Src++);
			word_len_origin++;
		}
		word_pos_origin++;
		word_origin[count_source].str[j] = '\0';
		word_origin[count_source].len = word_len_origin;
		word_origin[count_source].origin_pos = word_pos_origin;
		Src++;
		++count_source;
	}
	
	while(*Match != '\0')
	{
		j = 0;
		word_len_match = 0;
		//here we must add *Match!='\0' condition, cause if there is only one word in Match, 
		//under such condition, this loop while not teminate right now, until it meet '\0;
		//this is very dangerous
		while (*Match!=' ' && *Match!='\0')
		{
			word_match[count_match].str[j++] = tolower(*Match++);
			word_len_match++;
		}
		word_pos_match++;
		word_match[count_match].str[j]='\0';
		word_match[count_match].len = word_len_match;
		word_match[count_match].origin_pos = word_pos_match;
		Match++;
		++count_match;			
	}

	for (i=0; i<count_source; i++)
	{
		cout << word_origin[i].str<<" " <<word_origin[i].len << " " << word_origin[i].origin_pos<< " " << word_origin[i].match_pos<< endl;
	}
		cout << "------------------invinsible line. following is match string----------------- " << endl;
	for(i=0; i<count_match; i++)
	{
		cout << word_match[i].str<<" " <<word_match[i].len << " " << word_match[i].origin_pos<<" "<<word_match[i].match_pos<< endl;
	}
	
	/* insert sort word_match array */
	for(i=0; i<=count_match-1; i++)
	{
		Tword tmp ;
		for(j=0; j<=count_match-i-2; j++ )
		{
			/* here we will doing swap */
			if(word_match[j].len > word_match[j+1].len)
			{
				memcpy(tmp.str, word_match[j].str, word_match[j].len);
				tmp.str[word_match[j].len] = '\0';// remember here is word_match[j].len, not len+1
				tmp.origin_pos = word_match[j].origin_pos;
				tmp.match_pos = word_match[j].match_pos;
				tmp.len = word_match[j].len;


				memcpy(word_match[j].str,word_match[j+1].str, word_match[j+1].len);
				word_match[j].str[word_match[j+1].len] = '\0';
				word_match[j].origin_pos = word_match[j+1].origin_pos;
				word_match[j].match_pos = word_match[j+1].match_pos;
				word_match[j].len = word_match[j+1].len;

				memcpy(word_match[j+1].str, tmp.str, tmp.len);
				word_match[j+1].str[tmp.len] = '\0';
				word_match[j+1].origin_pos = tmp.origin_pos;
				word_match[j+1].match_pos = tmp.match_pos;
				word_match[j+1].len = tmp.len;
			}
		}
	}

	cout << "------------------invinsible line after bubble sort----------------------- " << endl;

	for(i=0; i<count_match; i++)
	{
		cout << word_match[i].str<<" " <<word_match[i].len << " " << word_match[i].origin_pos << " " << word_match[i].match_pos<< endl;
	}

	int l=0, k=0;
	/*The following for loop is used to match the sorce word*/
	for(i=count_match-1; i>=0; i--)
	{
		
		int len_mat = word_match[i].len;
		for(j=0; j<count_source; j++)
		{
			char *mat = word_match[i].str;
			int len_src = word_origin[j].len;
			// match position equal -1, means that this origin string haven't been match yet;
			if(word_origin[j].match_pos==-1)
			{
				char *src = word_origin[j].str;
				/*int max_match = 0;
				char *src = word_origin[j].str;
				while(*src!='\0' && *mat!='\0')
				{
					if(*src==*mat)
					{
						max_match++;
					}
					src++;mat++;
				}*/
				char *tmpx = strstr(src,mat);
				if(tmpx!=NULL)
				{
					word_origin[j].match_pos = 999;
					word_match[i].match_pos = j+1;
					break;
				}


				/*if(max_match == len_mat)
				{
					word_origin[j].match_pos = 999;
					word_match[i].match_pos = j+1;
					break;
				}*/
			}
		} 
	}/// end for for(i=0; i<count_match; i++)
	cout << "---------------------after match----------------"<< endl;
	for(i=0; i<count_match; i++)
	{
		cout << word_match[i].str<<" " <<word_match[i].len << " " << word_match[i].origin_pos << " " << word_match[i].match_pos<< endl;
	}


	int index = 0;
	for(i = 0; i<count_match; i++)
	{
		if(word_match[i].match_pos==-1)// equal to -1 means there is no match word
			index++;
	}
	if(index==count_match) //no word is matched
		return 0;
	
	index = 0;
	for(i = 0; i<count_match; i++)
	{
		if(word_match[i].match_pos != -1)
			index++;
	}
	if(index>0 && index<count_match)
		return 3;// only some of the words is matched;

	int flag = 0;
	if(index==count_match)// all the word is matched, we need to determine the sequence
	{
		int mp1 = 0;
		int mp2 = 0;
		int or1 = 0;
		int or2 = 0;
		for(i=0; i<count_match; i++)
		{
			mp1 = word_match[i].match_pos;
			or1 = word_match[i].origin_pos;
			for(j=0; j<count_match && j!=i; j++)
			{
				mp2 = word_match[j].match_pos;
				or2 = word_match[j].origin_pos;
				if(((mp1<mp2)&&(or1<or2))||((mp1>mp2)&&(or1>or2)))
				{
					
				}
				else
				{
					flag = 1;
				}
			}
		}
	}
	if(flag==1)
		return 2;
	else
		return 1;
}


/* mian函数已经隐藏，这里保留给用户的测试入口，在这里测试你的实现函数，可以调用printf打印输出*/
/* 当前你可以使用其他方法测试，只要保证最终程序能正确执行即可 */
/* 该函数实现可以任意修改，但是不要改变函数原型。一定要保证编译运行不受影响*/
int main()
{
    /* TODO: 请测试时改变改用例 */	
	
    /* TODO: 调用被测函数 */
    	
    /* TODO: 执行完成后可比较是否是你认为正确的值 */
	
	char *input = "\101";//aaabbbccbbzz!!@#$%%";
	char *output = new char[strlen(input)+1];
	//DelChar(input, output); //brute force implementation
	DelChar2(input, output); //hash implementation
	cout << output << endl;
//	cout << "\x07" << endl;
	delete [] output;
	char *pcar = "4aaaa,a9aaa,aa3ab,aaa4z,aabb5,12341,12346,12342,12347,12343,12348,12344,12349,12345,12340";
	int date = 4;
	char *plimit = new char[strlen(pcar)+1];
	CalculateLimitingCarCard(pcar, date, plimit);
	cout << plimit << endl;
	delete [] plimit;
	
	char *src = "Hello world he is a programmer What the hell";
	char *match = " ";
	int mtmp = 3333333;
	mtmp = MultiWordMatch(src, match);
	cout << "match result: "<< mtmp << endl;
	return 0;
	
}


/*****************problem description, in chinese.*********************************/
/*
1 删除重复字符
给定一个字符串，将字符串中所有和前面重复多余的字符删除，其余字符先原有先后顺序保留并输出。区分大小写。

接口说明:

1）  实现函数：

int  DelChar(char* input, char *output)

2）参数说明：

输入参数 input 输入字符串

输出参数：output

 

如：输入abadcbad，输出abdc

2车牌限号
成都市从2012年4月5日开始对城区的主要干道实行尾号限行。为了帮组市民快速的查询自己的车牌是在哪天限行，特别邀请你写一个程序，输入一系列汽车的车牌号和限行的工作日，输出当天限行的车牌。当前限行规则是，车牌号的最后一位，如果1,6，周一限行；如果是2,7，周二限行；如果是3,8，周三限行；如果是4,9，周四限行；如果是5,0，周五限行；周六和周日对车牌不限行，如果车牌的最后一位不是数字而是字母，那么查询倒数第二位，如果倒数第二位也是字母，继续从右往左查看，直到查询到数字位置。当然，在中国的车牌中，是不会出现5为编号全部为字母的情况。车牌的长度是固定的，比如“川A01010”。由于限行对全国的车辆都有效，在程序中，用户不用输入地域编码“川A”，每个车牌号只需要输入后5位编号即可。后5位只能是数字或者字母,而且不能全是字母。考虑到使用者对系统的不了解，可能输入错误，请大家在程序中做出容错处理，如果发现输入牌照号不对，请返回-1。

 

1)        实现函数：

int CalculateLimitingCarCard(char *pCarCard,int dwDate, char *pLimitCarCard)

 

2)        参数说明：

输入：

pCarCard:汽车车牌号，不同车牌以“,”分隔，如：01010,0AB93,A967B

dwDate:范围（0--6）分别表示周日到周六

输出：

pLimitCarCard：当日限行的车牌, 不同车牌以“,”分隔，车牌输出顺序与输入顺序保持一致。如果当日没有车辆限行，输出空字符串

 

3)        返回值：

如果输入的车牌号格式或编号或日期不符合要求，请返回-1。

如果输入合法，返回0，同时输出当日限行的车牌。

 

例如：输入车牌：”01010,01027,01022”  ,  日期：2

      输出车牌：”01027,01022”

3：多单词匹配查找
在一个给定的源字符串中查找由若干个单词组成的字串（模式串），要求如下：

1、  源字符串与模式串组成格式为：单词<空格>单词<空格>单词...，不用考虑标点符号；源字符串与模式串部字符长度≤64；

2、  单词由数字、字母组成，不区分大小写；

3、  优先匹配模式串中字符多的单词，如模式串为”he hello hell”，源字符串为”hello world”，则源字符串中”hello”匹配模式串中的”hello”； 如果出现模式串中多个相同字符数的单词匹配源串中同一个单词，优先匹配模式串中先出现的，如模式串”he lo”，源串为”hello world”，则匹配模式串中的”he”匹配源串中的”hello”

4、  源字符串中单词被匹配顺序是:优先匹配完全相同的单词;如果有多个单词可以被匹配,优先匹配第一个.如:源字符串为”hell hello world hell he”,如果模式串为”he”,那么匹配”he”;如果模式串为”hel”,那么匹配第一个”hell”;如果模式串为”hell”,那么匹配”第一个”hell”;

5、  源字符串的单词只能被匹配一次，如上例中”hello”已经匹配了，此时”he”和”hell”不能再部分匹配”hello world”中的”hello”，又如模式串为”he hello hell”，源字符串为”hello world hello world”，模式串的”hello”匹配了文本串的第一个”hello”，则模式串的”hell”可以匹配源字符串的第二个”hello”；

1） 实现函数：

int MultiWordMatch(char *Src, char *Match)

2） 参数说明：

输入：源字符串，模式串（单词<空格>单词<空格>单词...）；

3）返回值：

类型：整型

错误或异常：-1

无匹配：0

完全匹配（模式串在源字符串中精确出现，次序也完全一样）：1

匹配（模式串的所有单词在整个源字符串中可以找到，但次序打乱）：2

部分匹配（模式串仅部分单词在源字符串中可以找到）：3 

例如：

文本串：“Hello world he is a programmer What the hell”

查找模式串”test”，输出0；

查找模式串”hello world”、”a prog”， 输出1；

查找模式串”what world”、”prog hell”， 输出2；

查找模式串”hello hello”、”nand ram”， 输出3；

*/
