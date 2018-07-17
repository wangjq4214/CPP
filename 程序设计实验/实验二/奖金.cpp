//¼ÆËã½±½ð.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	int r;
	double jj;
	
	cin >> r;
	
	if (r <= 100000)
	{
		jj = r * 0.1;
	}
	if (r > 100000 && r <= 200000)
	{
		jj = (r - 100000) * 0.075 + 10000;
	}
	if (r > 200000 && r <= 400000)
	{
		jj = (r - 200000) * 0.05 + 17500;
	}
	if (r > 400000 && r <= 600000)
	{
		jj = (r - 400000) * 0.03 + 27500;
	}
	if (r > 600000 && r <= 1000000)
	{
		jj = (r - 600000) * 0.015 + 33500;
	}
	if (r > 1000000)
	{
		jj = (r - 1000000) * 0.01 + 39500;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(2) << jj;
	
	return 0;
}
