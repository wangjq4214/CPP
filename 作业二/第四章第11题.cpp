//第四章第11题
#include <iostream>

using namespace std;

long pingfang(int);

int main() {
	int n;
	cout << "请输入一个整数：";
	cin >> n;
	
	cout << "结果为：" << pingfang(n);
}

long pingfang(int n) {
	if (n == 1) {
		return 1;
	} else {
		return n * n + pingfang(n - 1);
	}
}
