//10
#include <iostream>
#include <algorithm>

using namespace std;

struct sle {
	int num;
	int sum;
	sle() {
		num = 0;
		sum = 0;
	}
};

bool compare1(sle a, sle b) {
	return a.sum > b.sum;
}

bool compare2(sle a, sle b) {
	return a.num < b.num;
}

int main() {
	int m, n, k, l, d;
	cin >> m >> n >> k >> l >> d;
	sle yc[m];
	sle xc[n];

	for (int i = 1; i <= d; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		if (a == c) {
			xc[min(b, d)].num = min(b, d);
			xc[min(b, d)].sum++;
		} else {
			yc[min(a, c)].num = min(a, c);
			yc[min(a, c)].sum++;
		}
	}

	sort(yc, yc + m, compare1);
	sort(xc, xc + n, compare1);
	
	sort(yc, yc + k, compare2);
	sort(xc, xc + l, compare2);

	for (int i = 0; i < k; i++) {
		if (i != k - 1) {
			cout << yc[i].num << " ";
		} else {
			cout << yc[i].num << endl;
		}
	}

	for (int i = 0; i < l; i++) {
		if (i != l - 1) {
			cout << xc[i].num << " ";
		} else {
			cout << xc[i].num << endl;
		}
	}
}
