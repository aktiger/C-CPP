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
size_t find_next_not_of_star(char * rule, size_t rule_index)
{
  size_t	rule_len = strlen(rule);
  while(rule_index != rule_len)
  {
    if(rule[rule_index] == '*')
    {
      continue;
    }
    else
    {
      return rule_index;
    }
  }
  return rule_index;
}


char* my_find(char  input[],   char rule[])
{
    //write your code here
  if(input == NULL || rule == NULL)
  {
    return NULL;
  }
  size_t	rule_len	   = strlen(rule);
  size_t	input_len	   = strlen(input);
  size_t	first_input_index  = 0;
  size_t	second_input_index = 0;
  size_t	rule_index  = 0;
  while(second_input_index != input_len)
  {
    while(rule_index != rule_len )
    {
      if((rule[rule_index] == '?') || (rule[rule_index] == input[second_input_index]))
      {
	rule_index++;
	second_input_index++;
      }
      else if(rule[rule_index]=='*')
      {
	rule_index = find_next_not_of_star(rule, rule_index);
	if(rule_index == rule_len) // this means that, the following charactors are all stars
	{
	  return input;
	}
	else
	{
	  if((rule[rule_index] == '?') || (rule[rule_index] == inpunt[second_input_index]))
	  {
	    rule_index++;
	    second_input_index++;
	  }
	  else
	  {
	    
	  }
	}
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







