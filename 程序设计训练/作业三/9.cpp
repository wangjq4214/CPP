#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	vector<int> team1, team2;
	while (cin >> n && n != 0) {
		team1.clear();
		team2.clear();
		cin.get();
		for (int i = 0; i < n; ++i) {
			string str1;
			getline(cin, str1);
			// ·Ö´Ê 
			vector<string> temp;
			string str;
			for (int j = 0; j < str1.size(); ++j) {
				if (str1[j] == ' ') {
					temp.push_back(str);
					str.clear();
				} else {
					str += str1[j];
				}
			}
			
			temp.push_back(str);
			for (int j = 0; j < temp.size(); ++j) {
				if (temp[j] == "no") {
					if (i % 2 == 0) {
						team1.push_back(0);
					} else {
						team2.push_back(0);
					}
					break;
				} else if (temp[j] == "good") {
					if (i % 2 == 0) {
						team1.push_back(1);
					} else {
						team2.push_back(1);
					}
					break;
				}
			}
		}

		for (int i = 0; i < ceil(n / 2.0); ++i) {
			cout << i + 1 << " ";
		}

		cout << "Score" << endl;
		int sum = 0;
		for (int i = 0; i < ceil(n / 2.0); ++i) {
			if (team1[i] == 1) {
				cout << "O" << " ";
				sum++;
			} else {
				cout << "X" << " ";
			}
		}
		cout << sum << endl;
		sum = 0;
		for (int i = 0; i < floor(n / 2.0); ++i) {
			if (team2[i] == 1) {
				cout << "O" << " ";
				sum++;
			} else {
				cout << "X" << " ";
			}
		}
		if (n % 2 != 0) {
			cout << "- ";
		}
		cout << sum << endl;
	}
}
