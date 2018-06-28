#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, x, y;
	map<int, int> coin;
	while (cin >> n && n != 0) {
		cin >> x;
		for (int i = 0; i < x; ++i) {
			cin >> y;
			coin[y] = 0;
		}
		
		for (map<int, int>::iterator iter = coin.begin(); iter != coin.end(); ++iter) {
			
		}
		coin.clear();
	}
}
