//IPº∆À„
#include <iostream>

using namespace std;

int main() {
	char ch;
	int ip;
	
	cin >> ip;
	for (int i = 0; i < 4; i++) {
		if (ip < 0 || ip > 255) {
			cout << "NO";
			return 0;
		}
		cin >> ch;
		cin >> ip;
	}
	cout << "YES";
} 
