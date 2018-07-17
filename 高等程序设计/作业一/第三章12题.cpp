//ตฺศýีย12ฬโ

#include <iostream>

using namespace std;

int main()
{
	char ch1[6];
	char ch2[6];
	int num = 0;
	cin >> ch1;
	
	for (int i = 0; i < 6; i++)
	{
		if (ch1[i] >= 0 && ch1[i] <= 9)
		{
			num += 1;
		}
	}
	
	for (int i = 0; i < num; i++)
	{
		ch2[i] = ch1[num - (i + 1)];
	}
	
	cout << num << endl << ch1 << endl << ch2;
	
	return 0;
} 
