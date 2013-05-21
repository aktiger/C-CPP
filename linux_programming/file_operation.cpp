/*
For the practice of file operation in cpp
Date:   Mon May 20 22:38:18 CST 2013 @110775501
Author: justinzhng
Email:  uestczhangchao@gmail.com

 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
int main()
{
  std:: ofstream	f1("test.data");
  if(!f1) return 0;
  f1 << std::setw(20) << "Name: " << "James" << std::endl;
  f1 << std::setw(20) << "Home Address:" << " Sichuan Chengdu" << std::endl;
  f1.close();

  std::  fstream	f("test2.data", std::ios::out);
  f << 1234 << ' ' << 3.14 << 'A' << "How ary you" ;
  f.close();
  f.open("test2.data", std::ios::in);
  int			i = 0;
  double		d;
  char			c;
  char			s[20];
  f >> i >> d >> c;
  f.getline(s, 20);
  std::cout << i << std::endl;
  std::cout << d << std::endl;
  std::cout << c << std::endl;
  std::cout << s << std::endl;
  f.close();
  /* read the full file!! */
  std::ifstream fin("test3.data");

  if(!fin)
  {
    std::cout << "file doesn't exit " << std::endl;
    exit(-1);
  }

  while((c = fin.get()) != EOF) std::cout << c;
  fin.close();

  /* read many charector once */
  std::ifstream	fin2("test4.data");
  if (!fin2)
  {
    std::cout << "test4.date does not exit " << std::endl;
    exit(-1);
  }
  char	c2[80];
  std::cout << "test fin2" << std::endl;
  while(fin2.get(c2, 80, '\0') != NULL)
  {
    std::cout << c;
  }
  fin2.close();
  std::cout << "test fin2 end" << std::endl;
  /* use fin.read(c2, 80) to read a file */
  std::ifstream fin3("test4.data");
  if(!fin3)
  {
    std::cout << "test4.data doesn't exit " << std::endl;
    exit(-1);
  }
  while(!fin3.eof())
  {
    fin3.read(c2,80);
    std::cout.write(c2, fin3.gcount());
  }
  fin3.close();

  /* --copy binary files -- */
  std::ifstream	fin4("hello_world", std::ifstream::binary);
  if(!fin4)
  {
    std::cout << " hello_world does not exit " << std::endl;
    exit(-4);
  }
  fin4.seekg(0, fin4.end);
  size_t	length = fin4.tellg();
  fin4.seekg(0, fin4.beg);
  std::cout << "fin4 size = " << length << std::endl;
  
  std::ofstream	fout4("hello_world_bk", std::ifstream::binary);
  char		c4[8646];
  while(!fin4.eof())
  {
    fin4.read(c4, 80);
    fout4.write(c4, fin4.gcount());
  }
  fin4.close();
  fout4.close();
  std::cout << "Copy over " << std::endl;

  
  return 0;
}
