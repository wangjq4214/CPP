//ур12
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 12 == 0) {
			cout << i << " ";
		} else {
			int j = i;
			while (j != 0) {
				if (j % 100 == 12) {
					cout << i << " ";
					break;
				}
				j /= 10;
			}
		}

	}

	return 0;
}
