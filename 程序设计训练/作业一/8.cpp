#include <iostream>

using namespace std;

int judge[10][10] = {
	1, 1, 0, 0, 0, 0, 0, 1, 1, 0,
	1, 1, 0, 1, 1, 0, 0, 1, 1, 1,
	0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 1, 0, 0, 0, 1, 1, 1,
	0, 1, 0, 0, 1, 0, 0, 0, 1, 1,
	0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
	0, 0, 0, 0, 0, 1, 1, 0, 1, 0,
	1, 1, 0, 1, 0, 0, 0, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 1, 0, 1, 1, 1, 0, 1, 1, 1
};

int main() {
	int temp[10];
	while (cin >> temp[0] && temp[0] != -1) {
		for (int i = 1; i < 10; ++i) {
			cin >> temp[i];
		}
		int j = 0;
		for (j; j < 9; ++j) {
			if (!judge[temp[j]][temp[j + 1]]) {
				break;
			}
		}
		if(j == 9) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
