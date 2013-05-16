/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-22 18:50:23:
desc: a buggy program from bbs.qshpan.com, i use strerror(errno) to locate
the problem, the problem is that i didn't give the second command line arguments.
 After making it running properly, i add some exception handling code:)                
*/
#include<errno.h>
#include<sys/mman.h> 
#include<sys/types.h> 
#include<fcntl.h> 
#include<unistd.h> 
#include<string.h> 
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
typedef struct 
{ 
  char name[4]; 
  int age; 
}people; 
main(int argc,char** argv) 
{ 
   int fd ,i; 
   people *p_map; 
   char temp; 
   if(argc < 2){
       printf("usage %s filename\n",argv[0]);
       exit(EXIT_FAILURE);
   }
   fd=open(argv[1],O_CREAT|O_RDWR|O_TRUNC,00777); 
   if(fd == -1)
   {
   	printf("error:%s\n",strerror(errno));
	exit(EXIT_FAILURE);
   }
   lseek(fd,sizeof(people)*5-1,SEEK_SET); 
   write(fd,"",1); 
   p_map=(people*)mmap(NULL,sizeof(people)*10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0); 
   close(fd); 
   temp='a'; 
   for(i=0;i<10;i++) 
   { 
        temp += 1; 
	printf("%s\n",strerror(errno));
        memcpy((*(p_map+i)).name,&temp,2); 
        (*(p_map+i)).age=20+i; 
   } 
    printf("initialize over!\n"); 
    sleep(10); 
    munmap(p_map,sizeof(people)*10); 
    printf("umap ok!\n"); 
} 
