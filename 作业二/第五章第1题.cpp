//第五章第1题
#include <iostream>
#include <cstring> 

using namespace std;

void prime(int);

int main() {
	int n;
	cout << "请输入一个整数，我们将找出其之前的素数：" << endl;
	cin >> n;
	cout << "素数为：" << endl;
	prime(n);

	return 0;
}

void prime(int n) {
	bool isprime[n + 1];
	
	memset(isprime,true,sizeof(isprime));
	
	for (int i = 2; i < n + 1; i++) {
		if(isprime[i] == true) {
			for (int j = 2; i * j <= n; j++) {
				isprime[i * j] = false;
			}
		}
	}
	
	for (int i = 2; i <= n + 1; i++) {
		if (isprime[i] == true) {
			cout << i << " ";
		}
	}
}
