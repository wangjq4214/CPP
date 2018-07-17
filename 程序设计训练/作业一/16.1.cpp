#include <iostream>

using namespace std;

int main() {
	int n, w;
	cin >> n >> w;
	int temp[n];
	
	for (int i = 0; i < n; ++i) {
		cin >> temp[i];
	}
	
	int judge = 1;
	int real = 0, sum = 0;
	for (int i = 0; i <= w; i++) {
		real = i;
		judge = true;
		for (int j = 0; j < n; j++) {
			real += temp[j];
			if (real > w || real < 0) {
				judge = !judge;
				break;
			}
		}
		if (judge) {
			sum++;
		}
	}
	cout << sum;
} 
