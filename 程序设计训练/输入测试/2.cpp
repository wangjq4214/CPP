#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int store[n];
	for (int i = 0; i < n; ++i) {
		cin >> store[i];
	}
	
	sort(store, store + n);
	for (int i = 0; i < n; ++i) {
		cout << store[i] << " ";
	}
}
