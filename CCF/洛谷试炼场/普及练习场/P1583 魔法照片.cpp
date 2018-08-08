#include <iostream>
#include <algorithm>

using namespace std;

struct Person {
	int num;
	int W;
};

bool compare(const Person &x, Person &y) {
	if (x.W == y.W) {
		return x.num < y.num;
	}
	return x.W > y.W;
}

int main() {
	int n, k;
	cin >> n >> k;
	int E[10];
	Person record[n];
	for (int i = 0; i < 10; ++i) {
		cin >> E[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> record[i].W;
		record[i].num = i + 1;
	}
	
	sort(record, record + n, compare);
	for (int i = 0; i < n; ++i) {
		record[i].W += E[i % 10];
	}
	sort(record, record + n, compare);
	
	for (int i = 0; i < k; ++i) {
		cout << record[i].num << " ";
	}
}
