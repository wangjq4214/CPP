//สýื้ทรฮส4
#include <iostream>

using namespace std;

int main() {
	int x, y, js = 0;
	cin >> x >> y;
	int sort[x][y];
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> sort[i][j];
		}
	}
	for (int i = 0; i < x; i++) {
		js = 0;
		for (int j = 0; j < y; j++) {
			if (sort[i][j] % 2 == 0) {
				js++;
			}
		}
		cout << js << endl;
	}
}
