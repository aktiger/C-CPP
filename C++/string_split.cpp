/*
  This program is used to get the words of a string, seperated by space!
  Author: Justinzhang
  Email: uestczhangchao@gmail.com
  Time:2013-5-16 17:48
*/
#include <iostream>
#include <cstring>
#include <vector>
int main()
{
  std::string	str("Please split this sentence into tokens");
  std::vector<char *> split_result;
  char *	 cstr = new char[str.length()+1];
  std::strcpy(cstr, str.c_str());
  char		*p    = std::strtok(cstr, " ");
  while( p != 0)
  {
    std::cout << p << std::endl;
    split_result.push_back(p);
    p = strtok(NULL, " ");
  }
  std::cout << " split line ----------------------------------\n" << std::endl;
  for(std::vector<char *>::iterator it = split_result.begin(); it != split_result.end(); ++it)
  {
    std::cout << *it << std::endl;
  }
  return 0;
}
