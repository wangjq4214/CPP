#include <iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n && n != 0) {
		int sum = 0;
		while (n != 1) {
			if (n % 2 == 0) {
				n /= 2;
				sum++;
			} else {
				n = 3 * n + 1;
				n /= 2;
				sum++;
			}
		}
		cout << sum << endl;
	}
}
