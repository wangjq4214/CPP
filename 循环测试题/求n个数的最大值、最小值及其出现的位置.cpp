//求n个数的最大值、最小值及其出现的位置
#include <iostream>

using namespace std;

int main() {
	int n, max, min, temp, wz1 = 1, wz2 = 1;
	cin >> n;
	
	cin >> max;
	min = max;
	
	for (int i = 2; i <= n; i++) {
		cin >> temp;
		if (temp > max) {
			max = temp;
			wz1 = i;
		}
		if (temp < min) {
			min = temp;
			wz2 = i;
		}
	}
	
	cout << max << " " << wz1 << " " << min << " " << wz2;
	
	return 0;
}
