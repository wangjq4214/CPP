#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
	double wei[256];
	wei['C'] = 12.01, wei['H'] = 1.008, wei['O'] = 16.00, wei['N'] = 14.01;
	int n;
	string MM;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		double sum = 0;
		cin >> MM;
		for (int i = 0; i < MM.length(); ++i) {
			if (isupper(MM[i])) {
				if (isdigit(MM[i + 1])) {
					int num = 0;
					char ch = MM[i];
					while (isdigit(MM[++i])) {
						num = num * 10 + MM[i] - '0';
					}
					sum += wei[ch] * num;
					i--; 
				} else {
					sum += wei[MM[i]];
				}
			}
		}

		cout << setprecision(3) << fixed << sum << endl;
	}
}
