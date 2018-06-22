// Ğ¡ÊéÍ¯¡ª¡ªÃÜÂë
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	cin >> str;

	for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
		*iter += n;
		while (!(*iter >= 'a' && *iter <='z')) {
			*iter -= 26;
		}
	}

	cout << str;

	return 0;
}
