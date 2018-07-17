//第五章第16题2
#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "请输入一个字符串，我们将逆序输出：" << endl;
	string str;
	
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--) {
		cout << str[i];
	}
} 
