///ÏàÁÚÊı¶Ô 

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int zs[num];
	for (int i = 0; i < num; i++)
	{
		zs[i] = 0;
	} 
	int js = 0;
	
	for (int i = 0; i < num; i++)
	{
		cin >> zs[i];
	}
	
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (abs(zs[j] - zs[i]) == 1)
			{
				js++;
			}
		}
	}
	
	cout << js;
	
	return 0;
} 
