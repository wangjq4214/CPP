#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct student {
	string name;
	string num;
	int score;
};

bool compare(const student &s1, const student &s2) {
	return s1.score > s2.score;
}

int main() {
	vector<student> stu;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		student temp;
		cin >> temp.name;
		cin >> temp.num;
		cin >> temp.score;
		stu.push_back(temp);
	}
	sort(stu.begin(), stu.end(), compare);
	cout << stu.begin()->name << " " << stu.begin()->num << endl;
	cout << (stu.end() - 1)->name << " " << (stu.end() - 1)->num << endl;
}
