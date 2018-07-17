//7
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int juzhen[n][m];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> juzhen[i][j];
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (juzhen[i][j] == 0) {
				continue;
			}
			juzhen[i][j] = min(min(juzhen[i - 1][j], juzhen[i][j - 1]), juzhen[i - 1][j - 1]) + 1;
		}
	}
	
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(juzhen[i][j] > sum) {
				sum = juzhen[i][j];
			}
		}
	}
	
	cout << sum;
}
