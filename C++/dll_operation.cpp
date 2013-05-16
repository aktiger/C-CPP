/*This file is used to practice dll operation,
  I use : g++ -fpic -shared -o file.cpp file.so
  to generate a .so file, in the so file, i define a function,
  here i want to dlopen the file and use the function in it;
  Notice: should use compiling command: g++ -O2 dll_operation.cpp -ldl -o dll_operation
  author: Justinzhang
  email: uestczhangchao@gmail.com
  Time:2013-5-16 18:10 F4-B265
*/

#include <iostream>
#include <dlfcn.h>
#include <cstdio>
//#include "generate_so.h"

#define WARNING(fmt,...) fprintf(stderr,"[Warning][%s:%d]"fmt"\n",__FILE__, __LINE__, ##__VA_ARGS__)
typedef int(*FUNC_T)(float, int) ;
int main()
{
  std::string	so_path = "/home/zhangchao08/Dropbox/git-repository/C-CPP/C++/generate_so";
  void*		handler = dlopen(so_path.c_str(), RTLD_NOW);
  if(handler == NULL) {
    WARNING("dlopen(%s) failed(%s)", so_path.c_str(), dlerror());
    return -1;
 }
  //  void*	entry = dlsym(handler, "_Z9my_add_sofi");
   void*	entry = dlsym(handler, "my_add_so");
  if(!entry)
  {
    WARNING("entry error");
  }
  FUNC_T	func  = (FUNC_T)(entry);
  int re = func(2.0, 444);
  std::cout << "re=" << re << std::endl;
  dlclose(handler);
  return 0;
}

