#include <iostream>

using namespace std;

int main() {
	int n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	int store[2 * n];
	for (int i = 0; i < 2 * n; ++i) {
		cin >> store[i];
	}
	
	long long sum = 0;
	
	for (int i = 0; i < 2 * n - 1; ++i) {
		if (i % 2 == 0) {
			sum += (store[i + 1] - store[i]) * p1;
		} else {
			int temp = store[i + 1] - store[i];
			if (temp > t1 + t2) {
				sum += (t1 * p1 + t2 * p2 + (temp - t1 - t2) * p3);
			} else if (temp > t1) {
				sum += (t1 * p1 + (temp - t1) * p2);
			} else {
				sum += temp * p1;
			}
		}
	}
	cout << sum;
}
