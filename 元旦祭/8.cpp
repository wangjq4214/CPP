//8
#include <iostream>

using namespace std;

struct carpet {
	int a;
	int b;
	int x;
	int y;
};

int main() {
	int n, m, o;
	cin >> n;
	carpet store[n];
	
	for (int i = 0; i < n; i++) {
		cin >> store[i].a >> store[i].b;
		cin >> m >> o;
		store[i].x = store[i].a + m;
		store[i].y = store[i].b + o;
	}
	
	int p, q;
	cin >> p >> q;
	
	for (int i = n - 1; i >= 0; i--) {
		if (p >= store[i].a && p <= store[i].x && q >= store[i].b && q <= store[i].y) {
			cout << i+1 << endl;
			return 0;
		}
	}
	
	cout << "-1" << endl;
	return 0;
}
