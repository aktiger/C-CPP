#include <iostream>
using namespace std;
int  main()
{
unsigned long a,i;
	cin>>a;
          i=a;
	      while((a*a+1)%i!=0)
		  {i--;}
cout<<(2*a+(a*a+1)/i+i);
return 0;
}

