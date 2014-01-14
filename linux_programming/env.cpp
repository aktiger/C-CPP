
#include <stdlib.h>
#include <iostream>

int main()
{
  int	x = setenv("test_env", "fuckroot", 1);
  std::cout << getenv("test_env") << std::endl;
  if(0 == x){
    while(NULL != getenv("test_env"))  {
    
  }
    std::cout << "successful change" << std::endl;
  }  else  {
    std::cout << "set env error" << std::endl;
    exit(-1);
  }
  return 0;
}
