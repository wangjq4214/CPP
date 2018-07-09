#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int max;
	cin >> max;
	for (int i = 1; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp > max) {
			max = temp;
		}
	}
	
	cout << max;
}
