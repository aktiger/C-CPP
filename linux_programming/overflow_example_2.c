
#include <stdio.h>
#include <stdlib.h>

void g()
{
  printf("now inside g()!\n");
}


/* void f() */
/* { */
/*   int		i; */
/*   void *	buffer[1]; */
/*   printf("now inside f()!\n"); */

/*   // can only modify this section */
/*   // cant call g(), maybe use g (pointer to function) */

/*   // place the address of g all over the stack: */
/*   for (i=0; i<2; i++) */
/*     buffer[i] = (void*) g; */

/*   // and goodbye.. */
/* } */


/* void f() */
/* { */
/*   void	*x[1]; */
/*   printf("now inside f()!\n"); */
/*   // can only modify this section */
/*   // cant call g(), maybe use g (pointer to function) */
/*   x[-1]	= &g; */
/* } */

void f()
{
  //  printf("now inside f()!\n");
  // can only modify this section
  // cant call g(), maybe use g (pointer to function)

  /* x86 function epilogue-like inline assembly */
  /* Causes f() to return to g() on its way back to main() */
  asm(
      "mov %%rbp,%%rsp;"
      "pop %%rbp;"
      "push %0;"
      "mov    $0x0,%%eax;"
      "ret"
      :			/* no output registers */
      : "r" (&g)
      : "%rbp", "%rsp"
      );
}


int main (int argc, char *argv[])
{
  //f();
  asm (
       "mov %%rbp, %%rsp;"
       "pop %%rbp;"
       "push %0;"
       "mov    $0x0,%%eax;"
       "ret"
       :
       :"r" (&g)
       :"%rbp", "%rsp"
);
  return 0;
}
