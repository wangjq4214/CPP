//1 
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int two[33] = {0};
	int n;
	long sum = 0;
	cin >> n;
	int i = 31;
	while (n != 0) {
		two[i] = n % 2;
		n /= 2;
		i--;
	}
	
	for (i = 15; i >= 0; i--) {
		sum += two[i] * pow(2, 15 - i);
	}
	for (i = 31; i >= 16; i--) {
		sum += two[i] * pow(2, 47 - i);
	}
	cout << sum;
} 
