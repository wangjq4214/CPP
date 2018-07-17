//第六章第9题
#include <iostream>

using namespace std;

void zhuanzhi(int (*p1), int (*p2));

int main() {
	int jz[3][3];
	int zz[3][3];
	cout << "请输入一个3*3的矩阵：" << endl;
	int (*p1), (*p2);
	p1 = &jz[0][0];
	p2 = &zz[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> *(p1 + 3 * i + j);
		}
	}
	zhuanzhi(p1, p2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << *(p2 + 3 * i + j) << " ";
		}
		cout << endl;
	}
}

void zhuanzhi(int (*p1), int (*p2)) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(p2 + 3 * j + i) = *(p1 + 3 * i + j);
		}
	}
}
