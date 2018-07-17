//PascalµÄÂÃĞĞ
#include <iostream>

using namespace std;

int xingzou(int, int);
int n;
int sort[1000][1000] = {0};

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sort[i][j];
		}
	}

	cout << xingzou(0, 0);
}

int xingzou(int x, int y) {
	int sum = 0;

	if (x > n - 1 || y > n - 1) {
		return 0;
	} else {
		if (x == n - 1 && y == n - 1) {
			return 1;
		} else if (sort[x][y] != 0) {
			sum += xingzou(x + sort[x][y], y);
			sum += xingzou(x, y + sort[x][y]);
		} else {
			return 0;
		}
	}
	return sum;
}
