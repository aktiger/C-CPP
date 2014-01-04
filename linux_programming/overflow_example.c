#include <stdio.h>
#include <string.h>

long f()
{
  printf("hello fuck\n");
  return 0;
}

int main()
{
  int	 i;
  void *x[1] ;
  for (i = 0; i<8; i++)
  {
    x[i] = &f;
  }
  return 0;
}
