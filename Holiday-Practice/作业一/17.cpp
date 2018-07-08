#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 7 == 0) {
			cout << i << endl;
		} else {
			int j = i;
			while (j != 0) {
				if (j % 10 == 7) {
					cout << i << endl;
					break;
				}
				j /= 10;
			}
		}

	}

	return 0;
}
