// ´¹Ö±Ê÷×´Í¼
#include <iostream>
#include <map>

using namespace std;

int main() {
	map<char, int> value;

	for (char i = 'A'; i <= 'Z'; i++) {
		value[i] = 0;
	}

	string str;
	for (int i = 0; i < 4; i++) {
		getline(cin, str);
		for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
			if (*iter >= 'A' && *iter <= 'Z')
				value[*iter]++;
		}
	}

	int maxValue = 0;
	for (map<char, int>::iterator iter = value.begin(); iter != value.end(); iter++) {
		if (iter->second > maxValue) {
			maxValue = iter->second;
		}
	}

	for (int i = maxValue; i > 0; i--) {
		for (map<char, int>::iterator iter = value.begin(); iter != value.end(); iter++) {
			if (iter->first == 'Z') {
				if (iter->second >= i) {
					cout << "*" << endl;
				} else {
					cout << " " << endl;
				}
			} else {
				if (iter->second >= i) {
					cout << "* ";
				} else {
					cout << "  ";
				}
			}
		}
	}

	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

	return 0;
}
