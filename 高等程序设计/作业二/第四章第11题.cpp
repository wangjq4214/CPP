//�����µ�11��
#include <iostream>

using namespace std;

long pingfang(int);

int main() {
	int n;
	cout << "������һ��������";
	cin >> n;
	
	cout << "���Ϊ��" << pingfang(n);
}

long pingfang(int n) {
	if (n == 1) {
		return 1;
	} else {
		return n * n + pingfang(n - 1);
	}
}
