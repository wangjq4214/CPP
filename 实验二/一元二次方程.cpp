//一元二次方程.cpp

#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	
	cin >> a >> b >> c; 
	
	d = (b * b) - (4 * a * c);
	if (d > 0)
	{
		cout << "two";
	} 
	if (d == 0)
	{
		cout << "one";
	}
	if (d < 0)
	{
		cout << "zero";
	}
	
	return 0;
} 
