#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string str;
    while (getline(cin, str)) {
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

        for (int j = temp.size() - 1; j >= 0; --j) {
        	if (j == 0) {
        		cout << temp[j] << endl;
			} else {
				cout << temp[j] << " ";
			}
        }
    }
}
