//╩ьндйЩ
#include <iostream>
#include <cmath>

using namespace std;

int caozuo(int);

int main() {
	int n, k;
	cin >> n >> k;
	int m = caozuo(n);
	for (int i = 1; i <= k; i++) {
		if (n == m) {
			cout << n << endl << i - 1;
			return 0;
		} else {
			n += m;
		}
		m = caozuo(n);
	}
	cout << n << endl << k;
}

int caozuo(int n) {
	int m = n, js = 0;
	while (m != 0) {
		m /= 10;
		js++;
	}
	js--;
	while (n != 0) {
		m += (n % 10) * pow(10, js);
		js--;
		n /= 10;
	}
	return m;
}
