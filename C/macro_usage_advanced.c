
#include <stdio.h>
// '\'
#define PRINT1(a,b) \
  {   \
  printf("print a \n");   \
  printf("print b \n");   \
  }
// 'do{...}while(0)'
#define PRINT2(a,b) \
  do {    \
  printf("print a \n");   \
  printf("print b \n");   \
  } while(0)
// '#'
#define PRINT3(a,b) \
  do {    \
  printf("%s %d\n", #a, a);   \
  printf("%d %d\n", a, a);    \
  } while(0)
// ##
#define TYPE1(type, name)   type name_##type##_type
#define TYPE2(type, name)   type name##_##type##_type
#define ERROR_LOG(module) fprintf(stderr, "error : "#module"\n");
int main(int argc, char const *argv[])
{
  int a = 10;
  int b = 20;
  TYPE1(int, c);
  ERROR_LOG("addr");
  name_int_type = a;
  TYPE2(int, d);
  d_int_type = a;
  PRINT1(a,b);
  PRINT2(a,b);
  PRINT3(a,b);
    
  return 0;
}
