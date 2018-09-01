#include <iostream>

using namespace std;

long long b, p, k, m;

long long kuai(long long y) {
	if (y == 0) {
		return 1;
	} else {
		long long temp;
		temp = kuai(y / 2);
		if (y % 2 == 0)
			return temp * temp % k;
		else
			return temp * temp * m % k;
	}
}

int main() {
	cin >> b >> p >> k;
	if (b == k) {
		cout << b << "^" << p << " mod " << k << "=" << '0' << endl;
		return 0;
	}
	m = b % k;
	cout << b << "^" << p << " mod " << k << "=" << kuai(p) % k << endl;

	return 0;
}
