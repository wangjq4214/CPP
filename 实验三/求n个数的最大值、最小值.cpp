//求n个数的最大值、最小值.cpp

#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n, a = INT_MAX, b = INT_MIN, c;
	cin >> n;
	
	for (int i = 0; i < n; i ++)
	{
		cin >> c;
		
		if (a > c)
		{
			a = c;
		} 
		if (b < c)
		{
			b = c;
		}
	}
	
	cout << b << " " << a;
	
	return 0;
}
