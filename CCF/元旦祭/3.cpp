//3
#include <iostream>
#include <algorithm>

using namespace std;

bool gcd(int, int, int);

int main() {
	int X, Y;
	cin >> X >> Y;
	int sort[Y + 1] = {0};
	for (int i = X; i < Y + 1; i++) {
		if (i % X == 0) {
			sort[i] = 1;
		}
	}
	
	int sum = X * Y;
	int temp = 0;
	
	for (int i = X; i <= Y; i++) {
		if (sum % i == 0) {
			if (gcd(X, i, sum) && sort[sum / i]) {
				temp++;
			}
		}
	}
	
	cout << temp;
}

bool gcd(int X, int i, int sum) {
	int j = sum / i;
	for (int k = max(i, j); k >= X; k--) {
		if (j % k == 0 && i % k == 0 && k == X) {
			return true;
		}
		if (j % k == 0 && i % k == 0 && k != X) {
			return false;
		}
	}
	return false;
}
