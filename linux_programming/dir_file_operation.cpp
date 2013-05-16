/*
This file open a directory and read the file in it;
author: Justinzhang
email: uestczhangchao@gmail.com
Time: 2013-5-16 10:58 @F4-B265
 */
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#define FATAL(fmt,...) fprintf(stderr, "[Fatal Error][%s]:[%d]"fmt"\n", __FILE__, __LINE__, ##__VA_ARGS__); abort()
#define RT_NOTICE(fmt,...) fprintf(stderr,"[NOTICE][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define RT_DEBUG(fmt,...) fprintf(stderr,"[DEBUG][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define RT_WARNING(fmt,...) fprintf(stderr,"[WARN][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define RT_FATAL(fmt,...) fprintf(stderr,"[FATAL[%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__);abort()

int main()
{
  DIR			*dir = NULL;
  struct dirent *	 fileitem;
  dir			     = opendir("/home/zhangchao08/testdir");
  if(!dir)
  {
    FATAL("open dir fail");
  }

  while(fileitem = readdir(dir))
  {
    printf("%s\n", fileitem->d_name);
  }
  return 0;
}
