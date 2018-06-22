//×î´ó²¨¶¯

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int spj[num];
	int bd = 0;
	
	for (int i = 0; i < num; i++)
	{
		cin >> spj[i];
	}
	
	for (int i = 0; i < (num - 1); i++)
	{
		if (abs(spj[i] - spj[i + 1]) > bd)
		{
			bd = abs(spj[i] - spj[i + 1]);
		}
	}
	
	cout << bd;
	
	return 0;
} 
