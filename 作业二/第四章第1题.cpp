//第四章第1题
#include <iostream>

using namespace std;

int gys(int, int);
int gbs(int, int);

int main() {
	int a, b;
	cin >> a >> b;

	cout << "最大公约数：" << gys(a, b) << endl;
	cout << "最小公倍数：" << gbs(a, b) << endl;

	return 0;
}

int gys(int x, int y) {
	for (int i = x; ; i--) {
		if (x % i == 0 && y % i == 0) {
			return i;
			break;
		}
	}
}

int gbs(int x, int y) {
	for (int i = x; ; i++) {
		if (i % x == 0 && i % y == 0) {
			return i;
			break;
		}
	}
}
