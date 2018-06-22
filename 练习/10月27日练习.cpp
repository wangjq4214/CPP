//10ÔÂ27ÈÕÁ·Ï°

#include <iostream>

using namespace std;

int found(int);

int main()
{
	int n, k, x, y = 0, js = 0;
	cin >> n >> k;
	
	int sn[n];
	int cx[k];
	
	for (int i = 1; i < n; i++)
	{
		sn[y] = found(i);
		
		if (sn[y] != 0)
		{
			y++;
			js++;
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		cin >> cx[i];
	}
	
	cout << js << endl;
	
	for (int i = 0; i < k; i++)
	{
		cout << sn[cx[i] - 1] << " ";
	}
	
	return 0;
}

int found(int i)
{
	int sum, k; 
	for (int j = 1; j < i; j++)
	{
		k = j;
		sum = j;
		while (k != 0)
		{
			sum = sum + (k % 10);
			k = k / 10;
		}
		if (sum == i)
		{
			break;
		}
	} 
		
	if (sum != i)
	{
		return i;
	}
	else
	{
		return 0;
	}
	
}
