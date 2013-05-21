/*
字符串匹配问题，给定一串字符串，按照指定规则对其进行匹配，并将匹配的结果保存至output数组中，多个匹配项用空格间隔，最后一个不需要空格。
要求：
匹配规则中包含通配符？和*，其中？表示匹配任意一个字符，*表示匹配任意多个（>=0）字符。
匹配规则要求匹配最大的字符子串，例如a*d,匹配abbdd而非abbd,即最大匹配子串。
匹配后的输入串不再进行匹配，从当前匹配后的字符串重新匹配其他字符串。
要求实现函数：char* my_find(char  input[],   char rule[])
 
举例说明：
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

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{    
    //write your code here
  char *input = "abcd";
  char *rule = "abcd";

  my_find(input, rule);
  return 0;
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。







