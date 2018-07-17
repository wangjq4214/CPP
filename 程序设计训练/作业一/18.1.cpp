#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1, str2;
	char ch1, ch2;
	long long x = 0, y = 0;
	cin >> str1 >> ch1 >> str2 >> ch2;
	for (int i = 0; i < str1.length(); ++i) {
		if (str1[i] == ch1) {
			x = x * 10 + (str1[i] - '0');
		}
	}
	for (int i = 0; i < str2.length(); ++i) {
		if (str2[i] == ch2) {
			y = y * 10 + (str2[i] - '0');
		}
	}
	
	cout << x + y;
}
