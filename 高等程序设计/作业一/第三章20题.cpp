// ตฺศýีย20ฬโ

#include <iostream>

using namespace std;

int main()
{
	for(int i = 1; i <= 1000; i++)
	{
		int sum = 0;
		for (int j = 1; j <= (i / 2); j++)
		{
			if ((i % j) == 0)
			{
				sum += j;
			}	
		}
		
		if (sum == i)
			{
				cout << i << ", its factors are ";
				for (int k = 1; k <= (i / 2); k++)
				{
					if ((i % k) == 0)
					{
						cout << k << ",";
					}
				}
				
				cout << "\b" << ' ' << endl;
			}
	}
	
	return 0;
} 
