//�����µ�16��2
#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "������һ���ַ��������ǽ����������" << endl;
	string str;
	
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--) {
		cout << str[i];
	}
} 
