//�����µ�15��
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cout << "����n���ַ�����" << endl;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str[0] == 'A') {
			cout << str;
		}
	}
} 
