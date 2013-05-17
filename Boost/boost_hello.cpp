/*
Author:justinzhang
Email:uestczhangchao@gmail.com
Modified: 2013-5-17 14:50 @F4-B265
DESC:
The defalut include path on linux is: /usr/local/include/boost
The defalut library path on linux is /usr/local/lib
on linux platform , you should use the following compiling command:
$~ g++  boost_hello.cpp  -o boost_hello -lboost_regex
This command is wrong: g++ -lboost_regex boost_hello.cpp -o boost_hello
*/

#include <iostream>
#include <cassert>
#include <string>
#include <boost/regex.hpp>

int main() {
  // 3 digits, a word, any character, 2 digits or "N/A", 
  // a space, then the first word again
   boost::regex reg("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
  
  std::string correct="123Hello N/A Hello";
  std::string incorrect="123Hello 12 hello";
  
  assert(boost::regex_match(correct,reg)==true);
  assert(boost::regex_match(incorrect,reg)==false);
}
