//»­Í¼

#include <iostream>

using namespace std;

int main()
{
	int num1;
	cin >> num1;
	int num2 = num1 * 2;
	int a = 0, b = 0;
	
	int x[num2];
	int y[num2];
	int zbz[100][100] = {0};
	
	for (int i = 0; i < num2; i++)
	{
		cin >> x[i] >> y[i];
	}
	
	for (int i = 0; i < num1; i++)
	{
		for (int j = x[a]; j < x[a + 1]; j++)
		{
			for (int k = y[a]; k < y[a + 1]; k++)
			{
				zbz[j][k] = 1;
			}
		}
		
		a += 2;
	}
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (zbz[i][j] == 1)
			{
				b++;
			}
		}
	}
	
	cout << b;
	
	return 0;
} 
