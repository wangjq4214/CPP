#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string str;

	while (n--) {
		cin >> str;
		for (int i = 1; i <= str.size(); i++) {
			string temp1 = str.substr(0, i), temp2;
			if (str.size() % temp1.size() == 0) {
				while (temp2.size() != str.size()) {
					temp2 += temp1;
				}

				if (temp2 == str) {
					cout << i << endl;
					break;
				}
			}
		}
		if (n) {
			cout << endl;
		}
	}
}
