#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct STR {
	string str;
	int degree;
};

bool comp(const STR &x, const STR &y) {
	return x.degree < y.degree;
}

int main() {
	int n, m;
	cin >> n >> m;
	STR store[m];
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		cin >> store[i].str;
		for (int j = 0; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if(store[i].str[j] > store[i].str[k]) {
					sum++;
				}
			}
		}
		store[i].degree = sum;
	}
	
	stable_sort(store, store + m, comp);
	for (int i = 0; i < m; ++i) {
		cout << store[i].str << endl;
	}
}
