// Ñ¡Êý
#include <iostream>

using namespace std;

static int sum = 0;

void group(int*, int*, int, int, int, int, int);
int prime(int);

int main() {
	int n, k;
	cin >> n >> k;
	int count[n], store[k];

	for (int i = 0; i < n; i++) {
		cin >> count[i];
	}

	group(count, store, n, 0, 0, k, k);

	cout << sum;
	return 0;
}

int prime(int temp) {
	for (int i = 2; i < temp / 2; i++) {
		if (temp % i == 0) {
			return 0;
		}
	}

	return 1;
}

void group(int *count, int *store, int n, int start, int insert, int rest, int k) {
	if (rest == 0) {
		int temp = 0;
		for (int i = 0; i < k; i++)
			temp += store[i];
		sum += prime(temp);
		return;
	}

	int end = n - rest;
	for (int i = start; i <= end; i++) {
		store[insert] = count[i];
		group(count, store, n, i + 1, insert + 1, rest - 1, k);
	}
}
