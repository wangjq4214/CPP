#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
	int n;
	int min = INT_MAX;
	vector<int> temp;
	while (cin >> n) {
		if (min > n) {
			min = n;
		}
		temp.push_back(n);
		if (cin.get() == '\n') {
			for (int i = 0; i < temp.size(); ++i) {
				cout << temp[i] << " ";
			}
			cout << min;
			temp.clear();
			min = INT_MAX;
			cout << endl;
		}
	}
}
