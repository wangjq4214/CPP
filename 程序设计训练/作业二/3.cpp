#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const pair<pair<int, int>, vector<string> > &x, const pair<pair<int, int>, vector<string> > &y) {
	if (x.first.first == y.first.first) {
		return x.first.second < y.first.second;
	} else {
		return x.first.first < y.first.first;
	}
}

int main() {
	int n;
	cin >> n;
	map<pair<int, int>, vector<string> > store;
	for (int i = 0; i < n; ++i) {
		string str;
		int x, y;
		cin >> str >> x >> y;
		store[make_pair(x, y)].push_back(str);
	}
	
	vector<pair<pair<int, int>, vector<string> > > temp;
	for (map<pair<int, int>, vector<string> >::iterator iter = store.begin(); iter != store.end(); ++iter) {
		temp.push_back(make_pair(iter->first, iter->second));
	}
	
	sort(temp.begin(), temp.end(), comp);
	for (int i = 0; i < temp.size(); ++i) {
		cout << temp[i].first.first << " " << temp[i].first.second << " ";
		for (int j = 0; j < temp[i].second.size(); ++j) {
			cout << temp[i].second[j] << " ";
		}
		cout << endl;
	}
} 
