#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	int temp[n], store[n][n];
	memset(temp, 0, sizeof(temp));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> store[i][j];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (store[i][j]) {
				temp[0]++;
				for (int k = 1; k <= min(n - i, n - j); ++k) {
					
				}
			} 
		}
	}
}
