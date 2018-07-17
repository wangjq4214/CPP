//对角线元素和
#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0;
	cin >> n;
	
	int bk[n][n];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> bk[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		sum += bk[i][i];
	}
	
	cout << sum;
	return 0;
}
