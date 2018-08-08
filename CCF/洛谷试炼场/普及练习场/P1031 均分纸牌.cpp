#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int record[n];
	
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> record[i];
		sum += record[i];
	}
	
	sum /= n;
	for (int i = 0; i < n; ++i) {
		record[i] -= sum;
	}
	
	sum = 0;
	for (int i = 1; i < n; ++i) {
		if (record[i - 1] != 0) {
			record[i] += record[i - 1];
			record[i - 1] = 0;
			sum++;
		}
	}
	
	cout << sum;
}
