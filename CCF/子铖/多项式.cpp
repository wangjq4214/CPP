// ¶àÏîÊ½
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, temp;
	cin >> n;
	for (int i = n; i >= 0; i--) {
		cin >> temp;
		
		if (temp) {
			if (i != n && temp > 0)
				cout<<"+";
			if (abs(temp) > 1 || i == 0)
				cout << temp;
			if (temp == -1 && i)
				cout << "-";
			if (i > 1)
				cout << "x^" << i;
			if (i == 1)
				cout << "x";
		}
	}
}
