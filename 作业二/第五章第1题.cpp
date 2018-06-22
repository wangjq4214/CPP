//�����µ�1��
#include <iostream>
#include <cstring> 

using namespace std;

void prime(int);

int main() {
	int n;
	cout << "������һ�����������ǽ��ҳ���֮ǰ��������" << endl;
	cin >> n;
	cout << "����Ϊ��" << endl;
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
