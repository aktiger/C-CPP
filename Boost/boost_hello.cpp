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

  boost::regex						reg2("^\\/([^\\/\\?]*).*?");
  std::string						source = "/llllllll?";
  boost::match_results<std::string::const_iterator>	result;
  if( regex_search(source, result, reg2))
  {
    std::string result_string(result[0].first, result[0].second);
    std::cout << "result_string= " << result_string << std::endl;
  }
  
  boost::regex					reg("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
  std::string					input_string = "http://www.google.co.in/search/search/?h=test&q=examapl";
  boost::regex					exrp( "^(?:http://)?([^/]+)(?:/?.*/?)/(.*)$" );
  boost::match_results<std::string::const_iterator>	what1;
  if( regex_search( input_string, what1, exrp ) )
  {
    //std::cout << what[1].first << std::endl;
    std::string zero(what1[0].first, what1[0].second);
    std::cout << "zero:" << zero << std::endl;
    std::string	base_url( what1[1].first, what1[1].second );
    std::cout << base_url << std::endl;
    std::string	query( what1[2].first, what1[2].second );
    std::cout << query << std::endl;
  }

  
  std::string	correct			    = "123Hello N/A Hello";
  std::string	incorrect		    = "123Hello 12 hello";
  assert(boost::regex_match(correct,reg)   == true);
  assert(boost::regex_match(incorrect,reg) == false);

  boost::cmatch matched_string;
  boost::regex	rule("abcd");
  std::string	input("abcd");

  
  int	rt = boost::regex_match(input.c_str(), matched_string,  rule);
  for(size_t i = 0 ; i < matched_string.size(); i++)
  {
    std::cout << "matched_string " << i << " is :" << matched_string[i].str() << std::endl;
  }
  std::cout << "rt = " << rt << std::endl;

  boost::regex	expression("^select ([a-zA-Z]*) from ([a-zA-Z]*)");
  boost::cmatch what;
  std::string	in;
  std::cout << "enter test string" << std::endl;
  /*
  getline(std::cin, in);
  if(regex_match(in.c_str(), what, expression))
    {
      for (size_t i = 0; i < what.size(); i++)
      {
	std::cout << "str: " << what[i].str() << std::endl;
      }
    }
    else
    {
      std::cout << "Error input" << std::endl;
    }
  */
    return 0;
}
