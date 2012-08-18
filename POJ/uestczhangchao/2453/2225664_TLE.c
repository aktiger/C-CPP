 #include"stdio.h"
 #include"math.h"
 long int progress(long int n)
 { int c,b=0,d=0;
    while(n!=0)
      {c=n%2;n/=2;b+=c;}  
     while(d!=b)
       {  while(++n!=0)
             {c=n%2;n/=2;d+=c;}          }   
    return(n);
 }
 main()
 {int i=1,n,b;
  long int a[1001];
     scanf("%ld",&a[1]);
      while(a[i]!=0)
        {i++;
          scanf("%ld",&a[i]);           }
       n=i;
   for(i=1;i<n;i++)
       {  b=progress(a[i]); 
         printf("%ld\n",b);
        }
 }  
 
