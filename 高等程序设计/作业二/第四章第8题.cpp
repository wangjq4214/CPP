//第四章第8题
#include <iostream>

using namespace std;

double lrd(int, double); 

int main() {
	int a;
	double b;
	cout << "请输入勒让德多项式的项数与x" << endl;
	cin >> a >> b;
	
	cout << "勒让德多项式的第n项为：" << lrd(a, b); 
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
