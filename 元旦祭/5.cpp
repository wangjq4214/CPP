//5
#include <iostream>

using namespace std;

int main() {
	int n, p;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p;
		int temp = p;
		for (int j = 1; j <= p; j++) {
			int k = j;
			while (k != 0) {
				if (k % 10 == 7) {
					temp--;
					break;
				}
				k /= 10;
			}
		}
		cout << temp << endl;
	}
}
