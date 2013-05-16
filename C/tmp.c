#include <stdio.h>
#include <stdarg.h>
int sum(int number, ...)
{
  va_list vaptr;
  int i = 0;
  int sum = 0;
  va_start(vaptr, number);
  for( i  = 0; i < number; i++)
  {
    sum += va_arg(vaptr, int);
  }
  return sum;
}

int main()
{
  printf("%d\n", rand(4));
  printf("%d\n", sum(4,4,3,2,1));
  return 0;
}
