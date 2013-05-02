#include <iostream>
#include <stdio.h>
using namespace std;
union uu
{
  short int a;
  unsigned char b[2];
  int c;
      
};

int main()
{
    cout << sizeof(uu) << endl;
    cout << sizeof(int)<<endl;
    cout << sizeof(long) << endl;
    cout << sizeof(short int)<<endl;
    cout << sizeof(double) <<  endl;
    uu u;
    u.b[0]=0x0a;
    u.b[1]=0x01;

    printf("%d\n",u.a);
    printf("%x\n",u.a);
    //    system("pause");
    return 0;
}
