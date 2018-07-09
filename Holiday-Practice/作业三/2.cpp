#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; ++i) {
		string str;
		getline(cin, str);
		vector<string> temp;
		string str1;
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] == ' ') {
				temp.push_back(str1);
				str1.clear();
			} else {
				str1 += str[j];
			}
		}
		temp.push_back(str1);

		for (int j = 0; j < temp.size(); ++j) {
			for (int k = temp[j].size() - 1; k >= 0; --k) {
				cout << temp[j][k];
			}
			if (j == temp.size() - 1) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
	}
}
