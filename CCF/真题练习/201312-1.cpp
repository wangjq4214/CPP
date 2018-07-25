#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map <int, int> record;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		record[temp]++;
	}
	
	int max = 0;
	int x;
	for (map<int, int>::iterator iter = record.begin(); iter != record.end(); ++iter) {
		if (iter->second > max) {
			max = iter->second;
			x = iter->first;
		}
	}
	
	cout << x;
	
	return 0;
}
