//分解质因数
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			cout << n << "=";
			while (i < n / 2) {
				if (n % i == 0) {
					cout << i << "*";
					n /= i;
				} else {
					i++;
				}
			}
			cout << n;
			return 0;
		}
	}

	cout << "no answer";
	return 0;
}
