//12
#include <iostream>
#include <string>

using namespace std;

struct people {
	string name;
	int d;
};

int main() {
	int n, m;
	cin >> n >> m; 
	people peop[n];
	
	for (int i = 0; i < n; i++) {
		cin >> peop[i].d >> peop[i].name;
	}
	
	int j = 0;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; 
		if ((peop[j].d == 0 && a == 1) || (peop[j].d == 1 && a == 0)) {
			j = (j + b) % n;
		} else {
			j = j - (b % n);
			if (j < 0) {
				j += n;
			}
		}
	}
	
	cout << peop[j].name << endl;
}
