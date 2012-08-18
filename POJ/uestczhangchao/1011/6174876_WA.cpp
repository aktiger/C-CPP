	#include <iostream>
	using namespace std;
	int main()
	{
		int cnt;
		int i;
		int array[100];
		int tmp = 0;
		int sum;
		int max = -1;
		cin >> cnt;
		while (cnt != 0)
		{
			sum = 0;
			max = -1;
			for(i=1; i <= cnt; i++)
			{
				cin >> tmp;
				sum += tmp;
				if (tmp > max)
				{
					max = tmp;
				}

			}
			while (sum % max != 0)
			{
				max++;
			}
			cout << max << endl;
			cin >> cnt;
		}
		return 0;
	}