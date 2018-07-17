#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x;
	vector<vector<int> > temp;
	int max;
	int count = 0;
	while (cin >> x) {
		if(temp.size() == 0) {
			vector<int> temp2;
			temp2.push_back(x);
			temp.push_back(temp2);
			max = x;
		} else {
			vector<int> temp2;
			for (int i = 0; i < temp[count].size(); ++i) {
				temp2.push_back(x + temp[count][i]);
			}
			temp2.push_back(x);
			temp.push_back(temp2);
			if (max < *max_element(temp2.begin(), temp2.end())) {
				max = *max_element(temp2.begin(), temp2.end());
			}
			count++;
		}
	}

	cout << max;
}
