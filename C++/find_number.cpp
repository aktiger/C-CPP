/*
  Author: justinzhang
  Email:  uestczhangchao@gmail.com
  Time:   Fri Sep 20 00:43:40 CST 2013
  Desc:   find nubmber in a number/char intersect string.
 */

#include <iostream>
#include <vector>

int find_prv_city(std::vector<std::string> &data, std::string code)
{
  size_t	i1  = 0, i2=0, i3=0, i4=0;
  size_t	i   = 0;
  int		ret = 0;
  code = code + "&&";
  char		*prv_city = const_cast<char *>(code.c_str());
  std::cout << code.length() << std::endl;
  std::cout << code << std::endl;
  std::cout << strlen(prv_city) << std::endl;

  while((isdigit(prv_city[i]) == 0) && (i < strlen(prv_city)))  {
    i++;
  }
  
  if(i == strlen(prv_city)){
      ret = -1;
  }
  i1 = i;

  while(isdigit(prv_city[i]) != 0 && i < strlen(prv_city))
  {
    i++;
  }
  if(i == strlen(prv_city)){
      ret = -1;
  }
  i2 = i;

  std::cout << "i1=" << i1 << " i2=" << i2 << std::endl;

  while((isdigit(prv_city[i]) == 0) && (i < strlen(prv_city)))  {
    i++;
  }

  if( i == strlen(prv_city)){
      ret = -1;
  }
  i3 = i;

  while(isdigit(prv_city[i]) != 0 && i < strlen(prv_city))  {
    i++;
  }
  
  if( i == strlen(prv_city)){
      ret = -1;
  }
  i4 = i;

  if(ret == 0)  {
    std::cout << "i3=" << i3 << " i4=" << i4 << std::endl;

    std::string	tmp(prv_city);

    data.push_back(code.substr(i1,i2-i1));
    std::cout << prv_city << std::endl;
    data.push_back(code.substr(i3, i4-i3));
  }

  return ret;
  
}

int main()
{
  std::vector<std::string>	test;
  std::string			code = "&&22222&&8";
  int				ret  = find_prv_city(test, code);
  std::cout << "ret = " << ret << std::endl; 
  std::cout << test.size() << "-------------" << std::endl;
  std::vector<std::string>::iterator	it   = test.begin();
  std::cout << *it << std::endl;
  ++it;
  std::cout << *it << std::endl;
  
  return 0;
}
