#include <iostream>

using namespace std;

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	char ch;
	int i;
	while ((ch = cin.get()) != EOF) {
		for (i = 1; s[i] && s[i] != ch; ++i);
		if (s[i]) {
			cout << s[i - 1];
		} else {
			cout << ch;
		}
	}
}
