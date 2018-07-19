#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>

using namespace std;

char change[] = {
	'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'  
};

int main() {
	int n;
	cin >> n;
	map<string, int> temp;
	for (int i = 0; i < n; ++i) {
		string str1, str2;
		cin >> str1;
		for (int j = 0; j < str1.size(); ++j) {
			if (str2.size() == 3) {
				str2 += "-";
			}
			if (!isdigit(str1[j])) {
				if (isupper(str1[j])) {
					str2 += change[str1[j] - 'A'];
				}
			} else {
				str2 += str1[j];
			}
		}
		temp[str2]++;
	}
	
	for (map<string, int>::iterator iter = temp.begin(); iter != temp.end(); ++iter) {
		if (iter->second > 1) {
			cout << iter->first << " " << iter->second << endl;
		}
	}
} 
