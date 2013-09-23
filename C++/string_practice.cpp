/*
Author: Justinzhang
Email: uestczhangchao@gmail.com
date: Fri Sep 20 22:53:08 CST 2013
Desc: for the purpose of practicing C++ String operation
 */

#include <iostream>

int main()
{
  
  std::string	s1 = "&33333&&9922";
  std::size_t	pos1 = std::string::npos;
  std::size_t	pos2 = std::string::npos;
  std::size_t	pos11 = std::string::npos;
  std::size_t   pos22 = std::string::npos;

  if(s1 == "&33333&&9922"){
    std::cout << "string equal const char " << std::endl;
  }
  
  pos1 = s1.find_first_not_of('&');
  if(pos1 != std::string::npos){
     pos11 = s1.find_first_of('&', pos1);
    if(pos11 != std::string::npos){
      std::cout << "in it " << std::endl;
      std::cout << s1.substr(pos1, pos11 - pos1) << "  know it " <<  std::endl;
    }
      
  }
    
  std::cout << "pos1= "<< pos1 << " pos11= " << pos11 << std::endl;

  if(pos11 != std::string::npos && pos1 != std::string::npos){
    pos2    = s1.find_first_not_of('&', pos11);
    if(pos2 != std::string::npos){
      pos22 = s1.find_first_of('&',pos2);
      std::cout << s1.substr(pos2, pos22 - pos2) << " second param " << std::endl;
    }
      
  }
    

  std::cout << "pos2= "<< pos2 << " pos22= " << pos22 << " pos22 - pos2 : " << pos22 - pos2 << std::endl;
  
  
  return 0;
}




