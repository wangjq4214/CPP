#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int find(int, int, int*, int*);

int main() {
	int n, x;
	while (cin >> n && n != 0) {
		cin >> x;
		int coin[x];
		for (int i = 0; i < x; ++i) {
			cin >> coin[i];
		}
		int num[n + 1] = {0};
		unsigned int sum = find(n, x, coin, num);
		if (sum == 0xFFFFFFFF) {
			cout << "Impossible" << endl;
		} else {
			cout << sum << endl;
		}
	}
}

unsigned int find(int n, int x, int *coin, int *num) {
	for (int i = 0; i < x; ++i) {
		if (n == coin[i]) {
			return 1;
		}
	}
	
	if (n == 0) {
		return 0;
	} else if (n < 0) {
		return 0xFFFFFFFF;
	}
	if (num[n] != 0) {
		return num[n];
	}
	
	vector<unsigned int> temp;
	for (int i = 0; i < x; ++i) {
		if (find(n - coin[i], x, coin, num) == 0xFFFFFFFF) {
			temp.push_back(0xFFFFFFFF);
		} else {
			temp.push_back(find(n - coin[i], x, coin, num) + 1);
		}
	}
	num[n] = *min_element(temp.begin(), temp.end());
	return num[n];
}
