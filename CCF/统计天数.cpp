// 统计天数
#include <iostream>

using namespace std;

int main() {
	int n, sum = 1, sum1 = 1;
	cin >> n;
	int temp[n];
	
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		if (temp[i + 1] > temp[i]) {
			sum1++;
		} else {
			sum1 = 1;
		}
		
		if (sum < sum1) {
			sum = sum1;
		}
	}
	
	cout << sum;
	
	return 0;
}
