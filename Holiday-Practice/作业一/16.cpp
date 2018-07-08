#include <iostream>

using namespace std;

int main() {
	long long A, B, C;
	int i = 1;
	while(cin >> A && A != EOF) {
		cin >> B >> C;
		if (A + B > C) {
			cout << "Case #" << i++ << ": true" << endl;
		} else {
			cout << "Case #" << i++ << ": false" << endl;
		}
	}
}
