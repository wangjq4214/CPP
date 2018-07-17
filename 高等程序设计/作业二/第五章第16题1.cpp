//第五章第16题
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	cout << "请输入一个字符串，我们将逆序输出：" << endl;
	char str[100000];
	
	cin >> str;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		cout << str[i];
	}
}
