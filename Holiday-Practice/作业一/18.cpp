#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string str1, str2, str3, str4;
	char ch1, ch2;
	long long x, y;
	cin >> str1 >> ch1 >> str2 >> ch2;
	for (int i = 0; i < str1.length(); ++i) {
		if (str1[i] == ch1) {
			str3 += str1[i];
		}
	}
	for (int i = 0; i < str2.length(); ++i) {
		if (str2[i] == ch2) {
			str4 += str2[i];
		}
	}
	
	stringstream stream1, stream2;
	stream1 << str3;
	stream1 >> x;
	stream2 << str4;
	stream2 >> y;
	cout << x + y;
}
