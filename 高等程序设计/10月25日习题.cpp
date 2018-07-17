//10ÔÂ25ÈÕÏ°Ìâ

#include <iostream>

using namespace std;

int main()
{
	int js = 0, pkp[25];
	
	for (int i = 0; i < 25; i++)
	{
		cin >> pkp[i];
	}
	
	for (int i = 1; i <= 13; i++)
	{
		js = 0;
		for (int j = 0; j < 25; j++)
		{
			if (i == pkp[j])
			{
				js++;
			}
		}
		
		if (js == 1)
		{
			cout << i;
			break;
		}
	}
	
	return 0; 
}
