/*
  Author: Justizhang
  Email:  uestczhangchao@gmail.com
  Date:   Mon Sep 23 15:14:36 CST 2013
  Desc:   for the purpose of practicing strptime and mktime ;
 */

#include <iostream>

int convert_time(const std::string &input_time_src)
{
  std::string tmp = input_time_src;
  std::size_t	index = input_time_src.find(" ");
  if( index != std::string::npos){
    tmp = input_time_src.substr(0, index);
  }
  const char *	format = "%d/%h/%Y:%T";
  struct tm	time;
  int		value  = 0;
  const char *	ret    = strptime(tmp.c_str(), format, &time);
  std::cout << "tmp=" << tmp.c_str() <<  " ret= " << ret << std::endl; 
  if( NULL != ret){
    value	       = mktime(&time);
    std::cout << "value = " << value << std::endl;
    return value;
  }  else {
    return 0;
  }
  
}



int main()
{
  const char * src = "12/Sep/2013:00:00:00 +0800";
  convert_time(src);
  return 0;
}

