#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define item 1000

/**s中的s1替换为s2**/
//加入了标志flag后，就可以替换字符串中第一个出现的子串

char *strRepl(char *s, char *s1, char *s2)
{
char *p,*sp,*dp,*pos;
int len,cnt;
int flag = 0;//为了只替换第一个单词而加入的判断标志
for (pos=s;;) {
	if(flag == 1)
	{
		flag = 0;
		return s;
	}
    if ((p = strstr(pos, s1)) == NULL) {
        flag = 0;
    	return s;
    }
    flag = 1;
    len = strlen(s2) - strlen(s1);
    if (len) {
      sp = p + strlen(s1);
      dp = sp + len;
      cnt = strlen(sp) + 1;
      memmove(p+strlen(s1)+len, p+strlen(s1), cnt);
    }
    memcpy(p, s2, strlen(s2));
    pos = p + strlen(s2);
    if (*pos == 0) {
    	flag = 0;
        return s;
    }
}
}



int main()
{
 FILE *fpt, *new, *after;
 char num[item][200], temp[1000];
 char *test = NULL;
 int i=0, j;

 fpt = fopen("D:\\scheduler.txt","r");
 if(fpt == NULL)
 {
	 perror("fpt File Open Error:");
	 exit(0);
 }
 new = fopen("D:\\new.txt","w");
 after = fopen("D:\\after.txt","w");
 if(new == NULL)
 {
	 perror("new open error");
	 exit(0);
 }


 //while(fscanf(fpt, "%[^' '] ", num[i]) != EOF){
 while(fscanf(fpt, "%[^\n] ", num[i]) != EOF){
 // fscanf(fpt, "%[^\n]\n", temp);
//	fscanf(fpt,"%s\n",temp);
	i++;
 }

 for(j=0; j<i; j++)

 {
	 //printf("[%d] %s\n", j, num[j]);
	 fprintf(new, "%s\n", num[j]);
 }

 for(j=0; j<i; j++)
 {
	 test = strRepl(num[j],"INTEGR","Scheduler");
	 printf("%s\n",test);
	 fprintf(after,"%s\n",num[j]);
 }

 fclose(fpt);
 fclose(new);
 fclose(after);
 return 0;
}
