#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.second > p2.second;
}

int main() {
	int n;
	cin >> n;
	map<int, int> total;
	vector<pair<int, int> > arr;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		total[x] += y;
	}

	for (map<int,int>::iterator iter = total.begin(); iter != total.end(); ++iter) {
		arr.push_back(make_pair(iter->first, iter->second));
	}
	
	sort(arr.begin(), arr.end(), compare);
	
	cout << arr.begin()->first << " " << arr.begin()->second;
}
