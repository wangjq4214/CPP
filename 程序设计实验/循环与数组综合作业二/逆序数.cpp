//ÄæĞòÊı
#include <iostream>

using namespace std;

int main() {
	int num, js = 0;
	cin >> num;
	int sort[num];
	for (int i = 0; i < num; i++) {
		cin >> sort[i];
	}
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (sort[i] > sort[j]) {
				js++;
			}
		}
	}
	cout << js;
}
