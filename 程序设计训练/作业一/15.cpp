#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int zl[num][num];
	zl[0][0] = 1;
	int j = 0;
	int k, l = 1;

	for (int i = 0; i < num - 1; i++) {
		j++;
		zl[i + 1][i + 1] = (zl[i][i] + j);
	}

	for (int i = 0; i < num; i++) {
		k = l;
		for (int j = i; j < num; j++) {
			++k;
			zl[i][j + 1] = zl[i][j] + k;
		}
		l++;
	}

	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			cout << zl[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
