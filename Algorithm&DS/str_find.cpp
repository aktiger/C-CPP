/*
�ַ���ƥ�����⣬����һ���ַ���������ָ������������ƥ�䣬����ƥ��Ľ��������output�����У����ƥ�����ÿո��������һ������Ҫ�ո�
Ҫ��
ƥ������а���ͨ�������*�����У���ʾƥ������һ���ַ���*��ʾƥ����������>=0���ַ���
ƥ�����Ҫ��ƥ�������ַ��Ӵ�������a*d,ƥ��abbdd����abbd,�����ƥ���Ӵ���
ƥ�������봮���ٽ���ƥ�䣬�ӵ�ǰƥ�����ַ�������ƥ�������ַ�����
Ҫ��ʵ�ֺ�����char* my_find(char  input[],   char rule[])
 
����˵����
input:abcadefg
rule:a?c
output:abc

input :newsadfanewfdadsf
rule: new
output: new new

input :breakfastfood
rule: f*d
output:fastfood
 */

#include <iostream>
#include <cstring>
using namespace std;

char* my_find(char  input[],   char rule[])
{
    //write your code here
  if(input == NULL || rule == NULL)
  {
    return NULL;
  }
  unsigned int len = strlen(input);
  unsigned int output_index = 0;
  cout << "len = " << len << endl;
  
  char	*output	= new char[2*len];
  if(output == NULL)
  {
    return NULL;
  }
  
  while(rule != NULL && input != NULL)
  {
    if(*rule != '*' && *rule != '?')
    {
      if(*rule == *input)
      {
	rule++;
	input++;
	output[output_index++] = *rule;
      }
    }
  }
}

//start ��ʾ���Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
int main()
{    
    //write your code here
  char *input = "abcd";
  char *rule = "abcd";
  my_find(input, rule);
  return 0;
}
//end //��ʾ���Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�







