#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int res[n][n], temp[n][n];
	memset(res, 0, sizeof(res));
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			cin >> temp[i][j];
			res[i][j] = temp[i][j];
		}
	}

	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j < i + 1; ++j) {
			res[i][j] = max(res[i][j] + res[i + 1][j], res[i][j] + res[i + 1][j + 1]);
		}
	}

	cout << res[0][0] << endl;

	cout << temp[0][0];
	int j = 0;
	for (int i = 0; i < n - 1; i++) {
		if (res[i + 1][j] <= res[i + 1][j + 1])
			j += 1;
		cout << " " << temp[i + 1][j];
	}
}
