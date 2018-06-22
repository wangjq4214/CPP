//×Ö·ûÕóÁĞ

#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	char zl[num][num];
	zl[0][0] = 'A';
	bool qr = true;
	int j = 0;
	int k, l = 1;
	
	for (int i = 0; i < num - 1; i++)
	{
		j++;
		zl[i + 1][i + 1] = (zl[i][i] + j);
		qr = true;
		while (qr)
		{
			if (zl[i + 1][i + 1] >= 'A' && zl[i + 1][i + 1] <= 'Z')
			{
				qr = false;
			}else
			{
				zl[i + 1][i + 1] -= 26;
			}
		}
	}
	
	for (int i = 0; i < num; i++)
	{
		k = l;
			
		for (int j = i; j < num; j++)
		{
			++k;
			
			zl[i][j + 1] = zl[i][j] + k;
			
			qr = true;
			while (qr)
			{
				if (zl[i][j + 1] >= 'A' && zl[i][j + 1] <= 'Z')
				{
					qr = false;
				}else
				{
					zl[i][j + 1] -= 26;
				}
			}
		}
		l++;
	}
	
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			cout << zl[i][j] << " ";
		}
		
		cout << endl;
	}
	
	return 0;
} 
