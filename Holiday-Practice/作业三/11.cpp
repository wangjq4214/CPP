#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		if (i % n == 0) {
			cout << i << " ";
		} else {
			string str1, str2;
			stringstream sstr1, sstr2;
			sstr1 << i;
			sstr1 >> str1;
			sstr2 << n;
			sstr2 >> str2;
			if (str1.find(str2) != string::npos) {
				cout << i << " ";
			}
		}

	}

	return 0;
}
