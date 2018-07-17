//ÇóºÍ.cpp

#include <iostream>

using namespace std;

int main()
{
	int sum1 = 0, sum2 = 0, n, i1 = 1, i2 = 1;
	
	cin >> n;
	
	while (i1 <= n)
	{
		while (i2 <= i1)
		{
			sum1 += i2;
			i2 ++;
		}
		sum2 += sum1;
		i1 ++;
	}
	
	cout << sum2;
	
	return 0;
 } 
