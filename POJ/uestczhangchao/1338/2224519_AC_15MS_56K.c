#include <stdio.h>
#include <math.h>


int cmp(const void *p,const void *q)
{
        return *(int *)p - *(int *)q;
}

int main()
{
        int i,n,i1,i2,i3;
        int a[6000];
        i = 0;
        for(i1 = 0; i1 < 32; i1++)
                for(i2 = 0 ;i2 < 21; i2++)
                        for(i3 = 0; i3 < 15; i3++)
                                if(pow(2,i1)*pow(3,i2)*pow(5,i3) < 2100000000.0)
								{
                                                a[i++] = pow(2,i1)*pow(3,i2)*pow(5,i3);
                                }
        qsort(a,i,sizeof(a[0]),cmp);
        while(scanf("%d",&n) == 1 && n != 0){
                printf("%d\n",a[n-1]);
        }
        return 0;
}

