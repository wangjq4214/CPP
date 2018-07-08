#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int P1, P2, P3, A1, A2, A3;
	char ch;
	cin >> P1 >> ch >> P2 >> ch >> P3;
	cin >> A1 >> ch >> A2 >> ch >> A3;
	int P = P1 * 29 * 17 + P2 * 29 + P3;
	int A = A1 * 29 * 17 + A2 * 29 + A3;
	int x = A - P;
	int y = abs(x);
	if (x < 0) {
		cout << "-";
		cout << y / (29 * 17) << "." << (y % (17 * 29))/ 29 << "." << y % 29 << endl;
	} else {
		cout << y / (29 * 17) << "." << (y % (17 * 29)) / 29 << "." << y % 29 << endl;
	}
} 
