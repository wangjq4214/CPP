//最小公倍数和最大公约数
#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = a; ; i++) {
		if (i % a == 0 && i % b == 0) {
			cout << i;
			break;
		}
	}
	cout << endl; 
	for (int i = a; ; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i;
			break;
		}
	}
}
