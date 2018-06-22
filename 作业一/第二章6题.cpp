// ตฺถþีย6ฬโ

#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f, n;
	a = b = c = d = e = f = 12;
	n = 5;
	
	a += a;
	b -= 3;
	c *= 2 + 3;
	d /= d + d;
	e %= (n %= 2);
	f += f -= f *= f;
	
	cout << a << endl << b << endl << c << endl << d << endl << e << endl << f << endl;
	return 0;
} 
