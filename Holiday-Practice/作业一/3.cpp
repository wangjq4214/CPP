#include <iostream>

using namespace std;

int main() {
	int p, e, i, d;
	int num = 0;
	while (cin >> p >> e >> i >> d && p != -1) {
		int k = 0;
		for (k = d + 1; ; ++k) {
			if ((k - p) % 23 == 0) {
				break;
			}
		}
		for (k; ; k += 23) {
			if ((k - e) % 28 == 0) {
				break;
			}
		}
		for (k; ; k += 23*28) {
			if ((k - i) % 33 == 0) {
				break;
			}
		}
		cout << "Case " << ++num << ": the next triple peak occurs in " << k-d <<" days." << endl;
	}
	return 0;
}
