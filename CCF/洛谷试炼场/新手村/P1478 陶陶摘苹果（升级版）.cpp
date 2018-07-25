#include <iostream>
#include <algorithm>

using namespace std;

struct Apple {
	int xi;
	int yi;
};

bool compare(const Apple &x, const Apple &y) {
	return x.yi < y.yi;
}

int main() {
	int n, s;
	cin >> n >> s;
	Apple record[n];
	int a, b;
	cin >> a >> b;
	a += b;
	
	for (int i = 0; i < n; ++i) {
		cin >> record[i].xi >> record[i].yi;
	}
	
	sort(record, record + n, compare);
	
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (record[i].xi <= a && record[i].yi <= s) {
			sum++;
			s -= record[i].yi;
		}
	}
	cout << sum;
}
