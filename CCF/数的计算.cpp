// ÊıµÄ¼ÆËã 
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int count[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			count [i] += count[j];
		}
		count[i]++;
	}
	
	cout << count[n];
}
