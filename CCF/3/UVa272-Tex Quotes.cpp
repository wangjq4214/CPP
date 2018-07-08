#include <iostream>

using namespace std;

int main() {
	char ch;
	int q = 1;
	while ((ch = cin.get()) != EOF) {
		if (ch == '"') {
			cout << (q ? "``" : "''");
			q = !q;
		} else {
			cout << char(ch);
		}
	}
}
