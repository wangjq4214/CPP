//3.9

#include <iostream>

using namespace std;

int f(int x, int y, int z);

int main()
{
	cout << "������3��������" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	cout << "3�����нϴ��һ��Ϊ��" << f(a, b, c);
	
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
