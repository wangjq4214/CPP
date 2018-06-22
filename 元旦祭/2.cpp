//2
#include <iostream>

using namespace std;

int main() {
	int L, N;
	cin >> L >> N;
	int location[N];
	for (int i = 0; i < N; i++) {
		cin >> location[i];
	}

	int max = 0, min = 0;

	if (N == 0) {
		cout << "0 0";
	} else {
		for (int i = 0; i < N; i++) {
			int temp1 = location[i];
			int temp2 = (L + 1) - location[i];
			if (temp1 > temp2) {
				if (temp2 > min) {
					min = temp2;
				}
				if (temp1 > max)
					max = temp1;
			} else {
				if (temp1 > min) {
					min = temp1;
				}
				if (temp2 > max)
					max = temp2;
			}
		}
		cout << min << " " << max;
	}
}
