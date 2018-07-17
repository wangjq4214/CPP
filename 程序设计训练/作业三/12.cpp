#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	stack<string> back, advance;
	string now = "http://www.game.org/";
	while (true) {
		string str;
		getline(cin, str);
		if (str.find("VISIT") != string::npos) {
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
			while (!advance.empty()) {
				advance.pop();
			}
			back.push(now);
			now = temp[1];
			cout << now << endl;
		} else if (str == "BACK") {
			if (back.empty()) {
				cout << "Ignored" << endl;
			} else {
				advance.push(now);
				now = back.top();
				back.pop();
				cout << now << endl;
			}
		} else if (str == "FORWARD") {
			if (advance.empty()) {
				cout << "Ignored" << endl;
			} else {
				back.push(now);
				now = advance.top();
				advance.pop();
				cout << now << endl;
			}
		} else if (str == "QUIT") {
			break;
		}

	}
}
