#include<string.h> 
#include"stdio.h"
main()
{
 char a[100];
 int i,j;
 char c;
 char b[15];
 char change(char);
 nex:;
 scanf("%s",b);
 getchar();
 
 i=0;
 if(b[0]=='E'&&b[1]=='N'&&b[2]=='D'&&b[3]=='O'&&b[4]=='F'&&b[5]=='I'&&b[6]=='N'&&b[7]=='P'&&b[8]=='U'&&b[9]=='T')
  	 goto next;
 while((c=getchar())!='\n')
 {a[i]=c;
 i++;}
 a[i]='\0';
 scanf("%s",b);
 for(i=0;;i++)
 {
 if(a[i]=='\0')
 break;
 }
 i--;
 for(j=0;j<=i;j++)
 {
 a[j]=change(a[j]);
 }
 printf("%s",a);
 printf("\n");
 goto nex;
 
 next: ;
}


 char change(char x)
 
 {
  if(x>='A'&&x<'F')
  x=x+'V'-'A';
else  if(x>='F'&&x<='Z')
  x=x+'A'-'F';
  return x;
 }