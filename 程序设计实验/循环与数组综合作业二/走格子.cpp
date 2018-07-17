//×ß¸ñ×Ó 
#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int sort[num];
	for (int i = 0; i < num; i++) {
		cin >> sort[i];
	}
	
	for (int i = 0; ; i++) {
		int sum = i;
		for (int j = 0; j < num; j++) {
			sum += sort[j];
			if (sum < 0) {
				break;
			}
		}
		if (sum >= 0) {
			cout << i;
			break;
		}
	}
}



