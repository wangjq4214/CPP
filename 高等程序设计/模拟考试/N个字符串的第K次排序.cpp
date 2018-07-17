//N个字符串的第K次排序
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string str[n];
	
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			string temp;
			if (str[j] > str[j + 1]) {
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << str[i] << endl;
	}
}
