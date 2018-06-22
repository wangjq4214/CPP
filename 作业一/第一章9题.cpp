// ตฺาปีย9ฬโ

#include <iostream>

using namespace std;

int add(int, int); 

int main()
{
	int a, b, c;
	cin >> a >> b;
	c = add(a, b);
	cout << "a + b = " << c << endl;
	return 0;
} 

int add(int x, int y)
{
	return x + y;
}
