// »ð²ñ°ô
#include<iostream>

using namespace std;

int nu[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int matches(int n) {
	int k = 0;
	for (int i =  n; i != 0; i /= 10) {
		k += nu[i % 10];
	}
	if(n == 0) {
		k += nu[0];
	}
	return k;
}
int main() {
	int i, j, sum = 0, num;
	cin >> num;
	for (i = 0; i <= 1000; i++) {
		for (j = 0; j <= 1000; j++) {
			if (matches(i) + matches(j) + matches(i+j) + 4 == num) {
				sum++;
			}
		}
	}
	
	cout << sum;
	return 0;
}
