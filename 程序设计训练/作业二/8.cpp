#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int sum = 0;
		int count = (-1 + pow(1 + 4 * 2 * n, 0.5)) / 2;
		if (count * (count + 1) / 2 == n) {
			for (int i = 1; i <= count; ++i) {
				sum += (i * i);
			}
		} else {
			for (int i = 1; i <= count; ++i) {
				sum += (i * i);
			}
			int x = n - count * (count + 1) / 2;
			sum += (count + 1) * x;
		}
		cout << n << " " << sum << endl;
	}
}
