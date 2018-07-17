#include <iostream>

using namespace std;

int main() {
	int n, sum = 0;
	while (cin >> n && n != -1) {
		sum += n;
	}
	if (sum) {
		cout << sum;
	} else {
		cout << "null";
	}
}
