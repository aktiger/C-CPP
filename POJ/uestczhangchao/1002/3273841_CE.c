#include <stdio.h>
　　#include <stdlib.h>
　　typedef struct _Node
　　{
　　long lnumber ;
　　long ltime ;
　　struct _Node *lChild, *rChild ;
　　} Node ;
　　int Duplicate ;
　　Node *pHead ;
　　void insertnode (long i)
　　{
　　Node *pTemp, *pNew ;
　　if (pHead == NULL)
　　{
　　 pHead = malloc (sizeof (Node)) ;
　　 pHead->lnumber = i ;
　　 pHead->ltime = 1 ;
　　 pHead->lChild = NULL ;
　　 pHead->rChild = NULL ;
　　 return ;
　　}
　　pTemp = pHead ;
　　while (1)
　　{
　　 if (pTemp->lnumber == i)
　　 {
　　 pTemp->ltime++ ;
　　 Duplicate = 1 ;
　　 return ;
　　 }
　　 if (i < pTemp->lnumber)
　　 {
　　 if (pTemp->lChild)
　　 pTemp = pTemp->lChild ;
　　 else
　　 {
　　 pNew = malloc (sizeof (Node)) ;
　　 pNew->lnumber = i ;
　　 pNew->ltime = 1 ;
　　 pNew->lChild = NULL ;
　　 pNew->rChild = NULL ;
　　 pTemp->lChild = pNew ;
　　 return ;
　　 }
　　 }
　　 if (i > pTemp->lnumber)
　　 {
　　 if (pTemp->rChild)
　　 pTemp = pTemp->rChild ;
　　 else
　　 {
　　 pNew = malloc (sizeof (Node)) ;
　　 pNew->lnumber = i ;
　　 pNew->ltime = 1 ;
　　 pNew->lChild = NULL ;
　　 pNew->rChild = NULL ;
　　 pTemp->rChild = pNew ;
　　 return ;
　　 }
　　 }
　　}
　　}
　　long tonumber (char *str)
　　{
　　long k ;
　　int i ;
　　k = 0 ;
　　for (i = 0 ; str[i] ; i++)
　　{
　　 switch (str[i])
　　 {
　　 case '0':
　　 k *= 10 ;
　　 break ;
　　 case '1':
　　 k = k*10 + 1 ;
　　 break ;
　　 case '2':
　　 case 'A':
　　 case 'B':
　　 case 'C':
　　 k = k*10 + 2 ;
　　 break ;
　　 case '3':
　　 case 'D':
　　 case 'E':
　　 case 'F':
　　 k = k*10 + 3 ;
　　 break ;
　　 case '4':
　　 case 'G':
　　 case 'H':
　　 case 'I':
　　 k = k*10 + 4 ;
　　 break ;
　　 case '5':
　　 case 'J':
　　 case 'K':
　　 case 'L':
　　 k = k*10 + 5 ;
　　 break ;
　　 case '6':
　　 case 'M':
　　 case 'N':
　　 case 'O':
　　 k = k*10 + 6 ;
　　 break ;
　　 case '7':
　　 case 'P':
　　 case 'R':
　　 case 'S':
　　 k = k*10 + 7 ;
　　 break ;
　　 case '8':
　　 case 'T':
　　 case 'U':
　　 case 'V':
　　 k = k*10 + 8 ;
　　 break ;
　　 case '9':
　　 case 'W':
　　 case 'X':
　　 case 'Y':
　　 k = k*10 + 9 ;
　　 break ;
　　 }
　　}
　　return k ;
　　}
　　void dfs (Node *pNode)
　　{
　　if (!pNode)
　　 return ;
　　dfs (pNode->lChild) ;
　　if (pNode->ltime != 1)
　　 printf ("%.3ld-%.4ld %d\n", pNode->lnumber/10000, pNode->lnumber % 10000, pNode->ltime) ;
　　dfs (pNode->rChild) ;
　　}
　　int main()
　　{
　　long i, j ;
　　char str[50] ;
　　Node *pTemp ;
　　pHead = NULL ;
　　Duplicate = 0 ;
　　scanf ("%ld", &i) ;
　　for (j = 0 ; j < i ; j++)
　　{
　　 scanf ("%s", str) ;
　　 insertnode (tonumber(str)) ;
　　}
　　if (!Duplicate)
　　{
　　 printf ("No duplicates.\n") ;
　　 return 0 ;
　　}
　　pTemp = pHead ;
　　dfs (pTemp) ;
　　return 0 ;
　　}
