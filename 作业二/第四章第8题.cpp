//�����µ�8��
#include <iostream>

using namespace std;

double lrd(int, double); 

int main() {
	int a;
	double b;
	cout << "���������õ¶���ʽ��������x" << endl;
	cin >> a >> b;
	
	cout << "���õ¶���ʽ�ĵ�n��Ϊ��" << lrd(a, b); 
}

double lrd(int x, double y) {
	if (x == 0) {
		return 1;
	} else if (x == 1) {
		return y;
	} else {
		return ((2 * x - 1) * y - lrd(x - 1, y) - (x - 1) * lrd(x - 2, y)) / x;
	}
}
