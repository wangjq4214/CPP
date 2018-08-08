#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Person {
	int num;
	int time;
};

bool compare(const Person &x, const Person &y) {
	return x.time < y.time;
}

int main() {
	int m;
	cin >> m;
	Person person[m];

	for (int i = 0; i < m; ++i) {
		person[i].num = i + 1;
		cin >> person[i].time;
	}

	sort(person, person + m, compare);

	double sum = 0, temp = 0;
	for (int i = 0; i < m; ++i) {
		cout << person[i].num << " ";
		if (i != 0) {
			temp += person[i - 1].time;
			sum += temp;
		}
	}
	cout << endl;
	cout << setprecision(2) << fixed << sum / m;
}
