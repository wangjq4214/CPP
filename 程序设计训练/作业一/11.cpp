#include <iostream>
#include <string>

using namespace std;

const string re[] = {"(Zero)", "(One)", "(Two)", "(Three)", "(Four)", "(Five)", "(Six)", "(Seven)", "(Eight)", "(Nine)"};

int main() {
	int sum[10] = {0};
	string str1, str2;
	getline(cin, str1);
	for (int i = 0; i < str1.length(); ++i) {
		if (str1[i] <= '9' && str1[i] >= '0') {
			sum[str1[i] - '0']++;
			str2 += re[str1[i] - '0'];
		} else {
			str2 += str1[i];
		}
	}
	cout << str2 << endl;
	for (int i = 0; i < 10; ++i) {
		cout << sum[i] << " ";
	}
}
