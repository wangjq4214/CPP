#include <iostream>
#include <string>

using namespace std;

int main() {
	int m1, m2;
	string str;
	while(cin >> m1 >> m2) {
		cin >> str;
		int r1 = 0, r2 = 0, r3 = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'A') {
				r1 = m1;
			}
			if (str[i] == 'B') {
				r2 = m2;
			}
			if (str[i] == 'C') {
				m1 = r3;
			}
			if (str[i] == 'D') {
				m2 = r3;
			}
			if (str[i] == 'E') {
				r3 = r1 + r2;
			}
			if (str[i] == 'F') {
				r3 = r1 - r2;
			}
		}
		cout << m1 << ',' << m2 << endl;
	}
}
