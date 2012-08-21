#include <iostream>
using namespace std;

int main()
{
	int x,y;
	printf("%d\n",&x-&y);
	printf("%d\n",&y-&x);
	return 0;
}