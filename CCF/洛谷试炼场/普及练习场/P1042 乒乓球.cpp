#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	char ch;
	ios::sync_with_stdio(false);
	map<char, int> pp11, pp21;
	vector<map<char, int> > record;
	while (cin >> ch && ch != 'E') {
		if ((pp11['L'] >= 11 || pp11['W'] >= 11) && abs(pp11['L'] - pp11['W']) >= 2) {
			cout << pp11['W'] << ":" << pp11['L'] << endl;
			pp11.clear();
		}
		if ((pp21['L'] >= 21 || pp21['W'] >= 21) && abs(pp21['L'] - pp21['W']) >= 2) {
			record.push_back(pp21);
			pp21.clear();
		}
		pp11[ch]++;
		pp21[ch]++;
	}
	if ((pp11['L'] >= 11 || pp11['W'] >= 11) && abs(pp11['L'] - pp11['W']) >= 2) {
		cout << pp11['W'] << ":" << pp11['L'] << endl;
		pp11.clear();
	}
	record.push_back(pp21);
	cout << pp11['W'] << ":" << pp11['L'] << endl;
	cout << endl;

	for (int i = 0; i < record.size(); ++i) {
		cout << record[i]['W'] << ":" << record[i]['L'] << endl;
	}

}
