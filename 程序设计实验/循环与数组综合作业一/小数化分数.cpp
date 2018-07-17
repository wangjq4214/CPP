//小数化分数
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int gcd(int, int);

int main() {
	int num;
	cin >> num;
	while (num--) {
		char ch1[100] = {}, ch2[100] = {}, ch3[100] = {}, ch4[100] = {};
		int js1 = 0, js2 = 0;
		int x, y, m;
		cin >> ch1;
		for (int i = 2; ch1[i] != '\0'; i++) {
			if (ch1[i] == '(') {
				for (i = i + 1; ch1[i] != ')'; i++) {
					ch3[js2] = ch1[i];
					js2++;
				}
			} else {
				for (i; ch1[i] != '(' && ch1[i] != '\0'; i++) {
					ch2[js1] = ch1[i];
					js1++;
				}
				i--;
			}
		}
		if (js1 == 0 && js2 != 0) {
			y = pow(10, js2) - 1;
			x = atoi(ch3);
			m = gcd(x, y);
			cout << x / m << "/" << y / m << endl;
		} else if (js1 != 0 && js2 == 0) {
			y = pow(10, js1);
			x = atoi(ch2);
			m = gcd(x, y);
			cout << x / m << "/" << y / m << endl;
		} else {
			strcpy(ch4, ch2);
			strcat(ch2, ch3);
			int a = atoi(ch2);
			int b = atoi(ch4);
			x = a - b;
			y = pow(10, js1 + js2) - pow(10, js1);
			m = gcd(x, y);
			cout << x / m << "/" << y / m << endl;
		}
	}
}

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
