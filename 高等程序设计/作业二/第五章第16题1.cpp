//�����µ�16��
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	cout << "������һ���ַ��������ǽ����������" << endl;
	char str[100000];
	
	cin >> str;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		cout << str[i];
	}
}
