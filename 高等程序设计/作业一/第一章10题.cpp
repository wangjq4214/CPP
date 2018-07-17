//ตฺาปีย10ฬโ

#include <iostream>

using namespace std;

void sort(int, int, int);

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);
	return 0;
} 

void sort(int x, int y, int z)
{
	int temp;
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	if (z < x)
	{
		cout << z << ',' << x << ',' << y << endl;
	}
	else if (z < y)
	{
		cout << x << ',' << z << ',' << y << endl;
	}
	else
	{
		cout << x << ',' << y << ',' << z << endl;
	}
}
