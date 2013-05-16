/*
This file open a directory and read the file in it;
author: Justinzhang
email: uestczhangchao@gmail.com
Time: 2013-5-16 10:58 @F4-B265
 */
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#define FATAL(fmt,...) fprintf(stderr, "[Fatal Error][%s]:[%d]"fmt"\n", __FILE__, __LINE__, ##__VA_ARGS__); abort()
#define RT_NOTICE(fmt,...) fprintf(stderr,"[NOTICE][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define RT_DEBUG(fmt,...) fprintf(stderr,"[DEBUG][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define RT_WARNING(fmt,...) fprintf(stderr,"[WARN][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define RT_FATAL(fmt,...) fprintf(stderr,"[FATAL[%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__);abort()

int main()
{
  std::string path = "/home/zhangchao08/testdir";
  DIR			*dir = NULL;
  struct dirent *	 fileitem;

  printf("path = %s\n", path.c_str());
  dir			     = opendir(path.c_str());
  if(!dir)
  {
    FATAL("open dir fail");
  }

  while(fileitem = readdir(dir))
  {
    if(!fileitem)
    {
      RT_FATAL("Error readfile ");
    }
    char *	name	  = fileitem->d_name;
    char	line[7];
    printf("%s\n", name);
    if(strcmp(name, ".") != 0 && strcmp(name,"..")!=0)
    {
      printf("file name = %s\n", (path+'/'+name).c_str());
    FILE	*f = fopen((path+'/'+name).c_str(), "r");
    if(!f)
    {
      continue;
    }
      printf("file is not null \n");
      fgets(line, 6 , f);
      printf("line = %s\n", line);
      fclose(f);
    }
  }
  closedir(dir);
  return 0;
}
