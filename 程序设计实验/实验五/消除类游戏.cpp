//Ïû³ıÀàÓÎÏ· 

#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int cs[x][y];
	int th[x][y];
	int js = 0;
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> cs[i][j];
		}
	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			th[i][j]=0;
		}
	}
	
	for (int i = 0; i < x; i++)
	{
		js = 1;
		for (int j = 0; j < y; j++)
		{
			if (cs[i][j] == cs[i][j + 1])
			{
				js++;
			}else
			{
				if (js > 2)
				{
					while (js--)
					{
						th[i][j - js] = 1;
					}
				}
				js = 1;
			}
		}
	}
	
	for (int j = 0; j < y; j++)
	{
		js = 1;
		for (int i = 0; i < x; i++)
		{
			if (cs[i][j] == cs[i + 1][j])
			{
				js++;
			}else
			{
				if (js > 2)
				{
					while (js--)
					{
						th[i - js][j] = 1;
					}
				}
				js = 1;
		    }	
		}
	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (th[i][j] == 1)
			{
				cout << "0 ";
			}else
			{
				cout << cs[i][j] << " ";
			}
		}
		
		cout << endl;
	}
	
	return 0;
} 	
