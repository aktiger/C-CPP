#include <stdlib.h>
#include <stdio.h>
int main()
{
  char	*str = "    -1g";
  void	*p = str;
  printf("%p\n", p);
  unsigned int x =  strtoull(str, NULL, 30);
  printf("%s\n", str);
  printf("%d\n", x);
  return 0;
}
