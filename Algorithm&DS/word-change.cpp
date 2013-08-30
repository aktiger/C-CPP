/*
author:justinzhang
email:uestczhangchao@gmail.com
time:Sun Aug 18 20:50:43 CST 2013
desc: For the purpose of implement word change program

   给定一个单词集合Dict，其中每个单词的长度都相同。现从此单词集合Dict中抽取两个单词A、B，我们希望通过若干次操作把单词A变成单词B，每次操作可以改变单词的一个字母，同时，新产生的单词必须是在给定的单词集合Dict中。求所有行得通步数最少的修改方法。

Given:
   A	       = "hit"
   B	       = "cog"
   Dict	       = ["hot","dot","dog","lot","log"]
   Return
  [
     ["hit","hot","dot","dog","cog"],
     ["hit","hot","lot","log","cog"]
  ]
   即把字符串A = "hit"转变成字符串B = "cog"，有以下两种可能：
   "hit" -> "hot" ->  "dot" ->  "dog" -> "cog"；
   "hit" ->  "hot" ->  "lot" ->  "log"  ->"cog"
  
*/

#include <iostream>




int main()
{
  std::set<string>	dict;
  string		tmp;
  
  
  return 0;
}





