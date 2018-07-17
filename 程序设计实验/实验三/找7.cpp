//ур7.cpp

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		if (i % 7 == 0)
		{
			cout << i << " ";
		}
		else
		{
			int i1 = i;
			while (i1 != 0)
			{
				if (i1 % 10 == 7)
				{
					cout << i << " ";
					break;
				}
				i1 /= 10;
			}
		}
	}
	
	return 0;
}
