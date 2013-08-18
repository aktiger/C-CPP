#include <iostream>


unsigned clp2(unsigned x){
  x = x-1;
  x = x|(x>>1);
  x = x|(x>>2);
  x = x|(x>>4);
  x = x|(x>>8);
  x = x|(x>>16);
  return x+1;
}



int f1(unsigned x)
{
  int	n      = 1;
  if(x==0) return -1;
  if ((x>>16) == 0) {n = n+16; x = x<<16;}
  if ((x>>24) == 0) {n = n+8; x = x<<8;}
  if ((x>>28) == 0) {n = n+4; x = x<<4;}
  if ((x>>30) == 0) {n = n+2; x = x<<2;}
  n	       = n-(x>>31);
  return 31-n;
}

int xx(unsigned int n){
int	c = -1;
while(n)
 {
   n >>= 1;
   c++;
 }
}


int main()
{
  std::cout << clp2(3) << std::endl;
  std::cout << f1(3) << std::endl;
  std::cout << xx(3) << std::endl;
  return 0;
}
