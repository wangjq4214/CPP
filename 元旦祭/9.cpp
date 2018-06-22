//9
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string vote[n];

	for (int i = 0; i < n; i++) {
		cin >> vote[i];
	}

	int max = 0;

	for (int i = 1; i < n; i++) {
		if (vote[max].size() < vote[i].size()) {
			max = i;
		} else if (vote[max].size() == vote[i].size()) {
			if (vote[max] < vote[i]) {
				max = i;
			}
		}
	}

	cout << max + 1 << endl << vote[max] << endl;
}
