//ÕÛµþ·½Õó 

#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	int cssz, num;
	cin >> cssz;
	cin >> num;
	int zl[num][num];
	zl[0][0] = cssz;
	int l = -1;
	
	for (int i = 0; i < num - 1; i++)
	{
		l += 2;
		zl[0][i + 1] = (zl[0][i] + l);
	}
	
	for (int i = 1; i < num; i++)
	{
		int j = 0;
		
		for (j; j <= i; j++)
		{
			zl[j + 1][i] = zl[j][i] + 1;
		}
		
		j -= 1;
		int k = i;
		
		for (k; k > 0; k--)
		{
			zl[j][k - 1] = zl[j][k] + 1;
		}
	}
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << setw(4) << zl[i][j];
		}
		
		cout << endl;
	}
	
	return 0;

} 
