//4
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	char x[n], y[n], z[n] = {0};
	cin >> x;
	cin >> y;
	for (int i = 0; i < n; i++) {
		if (y[i] > x[i]) {
			cout << "-1";
			return 0;
		}
	}
	
	cout << y;
}
