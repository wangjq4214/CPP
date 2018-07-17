#include <iostream>
#include <utility>
using namespace std;

int gcd(int, int);

int main()
{
	int x, y;
	cin >> x >> y;
	int z = gcd(x, y);
	
	if (z == 1)
		cout << "Yes";
	else
		cout << "No";
}
int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}
