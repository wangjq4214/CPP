#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	int temp = (c * 60 + d) - (a * 60 + b);
	
	cout << temp / 60 << " " << temp % 60;
}
