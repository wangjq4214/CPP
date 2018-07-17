//3.9

#include <iostream>

using namespace std;

int f(int x, int y, int z);

int main()
{
	cout << "请输入3个整数：" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	cout << "3个数中较大的一个为：" << f(a, b, c);
	
	return 0; 
}

int f(int x, int y, int z)
{
	int max = x;
	if (max < y)
	{
		max = y;
	}
	if (max < z)
	{
		max = z;
	}
	
	return max;
}
