//第五章第2题
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int sort[n];
	
	for (int i = 0; i < n; i++) {
		cin >> sort[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sort[i] > sort[j]) {
				int temp;
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sort[i] << " ";
	}
}
