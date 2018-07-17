//≈¿≥Ê
#include <iostream>

using namespace std;

int main() {
	int n, u, d;
	
	cin >> n >> u >> d; 
	while (n != 0) {
		int pa = 0, i;
		for (i = 0; pa < n; i++) {
			if (i % 2 == 0)
				pa += u;
			else
				pa -= d;
		}
		cout << i << endl;
		cin >> n >> u >> d;
	}
}


