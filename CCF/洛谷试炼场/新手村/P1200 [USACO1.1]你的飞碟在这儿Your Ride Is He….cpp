#include <iostream>

using namespace std;

int main() {
	string str1, str2;
	int sum1 = 1, sum2 = 1;
	
	cin >> str1 >> str2;
	
	for (int i = 0; i < str1.size(); ++i) {
		sum1 *= (str1[i] - 'A' + 1);
	}
	for (int i = 0; i < str2.size(); ++i) {
		sum2 *= (str2[i] - 'A' + 1);
	}
	
	if (sum1 % 47 == sum2 % 47) {
		cout << "GO";
	} else {
		cout << "STAY";
	}
}
