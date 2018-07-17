// ½ñÏ¦ºÎÏ¦
#include <iostream>

using namespace std;

int pdrn(int);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int yyyy, mm, dd, sum = 0;
		char ch;

		cin >> yyyy >> ch >> mm >> ch >> dd;

		if (mm <= 2) {
			do {
				if (pdrn(yyyy)) {
					sum += 365;
				} else {
					sum += 366;
				}
				yyyy++;
			} while (sum % 7 != 0);
		} else {
			do {
				if (pdrn(yyyy + 1)) {
					sum += 365;
				} else {
					sum += 366;
				}
				yyyy++;
			} while (sum % 7 != 0);
		}
		cout << yyyy << endl;
	}
}

int pdrn(int x) {
	if ((x % 4 == 0 && x %100 != 0) || x % 400 == 0) {
		return 0;
	} else {
		return 1;
	}
}
