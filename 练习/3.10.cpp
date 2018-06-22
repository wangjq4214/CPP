//3.10

#include <iostream>

using namespace std;

int main()
{
	cout << "请输入一个数：" <<  endl;
	double x;
	cin >> x;
	
	if (x < 1)
	{
		cout << x;
	}
	else
	{
		if (x >= 10)
		{
			cout << 3 * x - 11;
		}
		else
		{
			cout << 2 * x - 1;
			
		}
	}
}
