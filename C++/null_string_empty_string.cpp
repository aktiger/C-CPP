/*
  Author: Justinzhang
  Email: uestzhangchao@gmail.com
  Time: Sun Sep 22 21:21:48 CST 2013
  Desc: for the understanding of null string and empty string , learn cpp try catch technical
 */


#include <iostream>

std::string fun(std::string s){
  if(s == ""){
    std::cout << "string s is null " << std::endl;
    return "";
  } else {
    throw std::string("Opps");
  }
}


int main()
{
  std::string	s1;
  if(s1.empty()){
    std::cout << "empty string" << std::endl;
  }

  std::string	s2 = "";
  if(s2.empty()){
    std::cout << "empty string using copy constructor" << std::endl;
  }

  std::string	s3("");
  if(s3.empty()){
    std::cout << "empty string using  a direct initialization and uses the string(const char*) constructor." << std::endl;
  }

  //  std::string s5(NULL);  //this is wrong
  try {
    fun("");
    
  }
  catch(std::string &e){
    std::cout << e << std::endl;
  }
    std::string	*s4 = NULL;
  //  std::cout << s4 << "Null" << std::endl;
  // if(s4.c_str() == NULL){
  //   std::cout << "null string " << std::endl;
  // }
  
  
  return 0;
}
