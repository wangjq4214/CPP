//第四章第10题 
#include <iostream>

using namespace std;

void convert(int);

int main() {
	int number;
	cout << "请输入一个整数：";
	cin >> number;
	cout << "输出：";
	if (number < 0) {
		cout << "-";
		number = -number;
	}
	convert(number);
	cout << endl;
	return 0;
}

void convert(int n) {
	int i;
	char c;
	if ((i = n / 10) != 0)
		convert(i);
	c = n % 10 + '0';
	cout << c;
}
