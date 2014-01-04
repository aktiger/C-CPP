#include <malloc.h>
#include <stdio.h>
#include <map.h>

int main()
{
  malloc_stats();
  map<int,float>	testmap;
  for(int i = 0; i< 10000000; i++){
    testmap[i] = float(i);
  }

  malloc_stats();
  testmap.clear();
  malloc_stats();
  return 0;
}
