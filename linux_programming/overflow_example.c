#include <stdio.h>
#include <string.h>

void fun()
{
  printf("hello fuck\n");
}


int main()
{
  //  int	value	      = 5;
  //  char	buffer_one[8] = "one";
  char	buffer_two[1] = "a";

  /* printf("buffer one address %p, content is:%s\n",buffer_one,buffer_one); */
  /* printf("buffer two address %p, content is: %s\n",buffer_two,buffer_two); */
  /* printf("value address %p, content is %d \n",&value,value); */

  //  strcpy(buffer_two,"AAAAAAAAAAAAAAAAAAAAAAA");

  //  printf("%c\n",*(char *)(buffer_two+23));
  //printf("fun address is %p\n",fun);
  //  *(int *)(buffer_two+6) = 0x4004a8;
  buffer_two[3] = 0x4004a8;
  
  /* printf("buffer one address %p, content is:%s\n",buffer_one,buffer_one); */
  /* printf("buffer two address %p, content is: %s\n",buffer_two,buffer_two); */
  /* printf("value address %p, content is %d \n",&value,value); */
  
  return 0;
}
