#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int str;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> str;
		int sum[10] = {0};

		for (int i = 1; i <= str; ++i) {
			sum[str - '0']++;
		}
		cout << sum[0];
		for (int i = 1; i < 10; ++i) {
			cout << " " << sum[i];
		}
	}
}
