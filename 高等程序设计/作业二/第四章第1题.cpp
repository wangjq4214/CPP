//�����µ�1��
#include <iostream>

using namespace std;

int gys(int, int);
int gbs(int, int);

int main() {
	int a, b;
	cin >> a >> b;

	cout << "���Լ����" << gys(a, b) << endl;
	cout << "��С��������" << gbs(a, b) << endl;

	return 0;
}

int gys(int x, int y) {
	for (int i = x; ; i--) {
		if (x % i == 0 && y % i == 0) {
			return i;
			break;
		}
	}
}

int gbs(int x, int y) {
	for (int i = x; ; i++) {
		if (i % x == 0 && i % y == 0) {
			return i;
			break;
		}
	}
}
