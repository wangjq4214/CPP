#include <iostream>

using namespace std;

int main() {
	int x, sum = 0;
	int status = 1;
	while (cin >> x && x) {
		if (x == 1) {
			status = 1;
		} else {
			if (status == 1) {
				status = 2;
			} else {
				status +=2;
			}
		}
		
		sum += status;
	}
	cout << sum;
} 
