// 校门口的树
#include <iostream>

using namespace std;

int main() {
	int L, M, temp1, temp2;
	cin >> L >> M;
	int num[L + 1] = {0};
	
	for (int i = 0; i < M; i++) {
		cin >> temp1 >> temp2;
		for (int j = temp1; j <= temp2; j++) {
			num[j] = 1;
		}
	}
	
	int sum = 0;
	for (int i = 0; i <= L; i++) {
		if (num[i] == 0) {
			sum++;
		}
	}
	
	cout << sum;
	
	return 0;
}
