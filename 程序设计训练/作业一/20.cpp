#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int sum[10] = {0};

	for (int i = 0; i < str.length(); ++i) {
		sum[str[i] - '0']++;
	}

	for (int i = 0; i < 10; ++i) {
		if (sum[i] != 0)
			cout << i << ":" << sum[i] << endl;
	}
}
