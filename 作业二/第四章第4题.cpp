//�����µ�4��
#include <iostream>

using namespace std;

long fac(int);

int main() {
	int a, b, c;
	cout << "������3������a��b��c" << endl; 
	cin >> a >> b >> c;
	
	cout <<"a!+b!+c!=" << fac(a) + fac(b) + fac(c);
	return 0;
}

long fac(int x) {
	int c = 1;
	for (int i = 1; i <= x; i++) {
		c *= i;
	}
	return c;
}
