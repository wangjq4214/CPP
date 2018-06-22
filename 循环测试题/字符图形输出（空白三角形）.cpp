//字符图形输出（空白三角形）
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n * 2 - 1; i++) {
		for (int j = 1; j <= (i <= n ? (i - 1) * 2 : (n * 2 - 1 - i) * 2); j++) {
			cout << " ";
		}
		for (int j = 1; j <= (i <= n ? (n * 2 - 1) - (i-1) * 2 : 2 * (i - n) + 1); j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
