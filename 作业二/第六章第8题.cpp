//�����µ�8��
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	cout << "������һ���ַ�����" ;
	getline(cin, str);
	char* p = &str[0];
	
	for (int i = 0; i < str.size(); i++) {
		if (isupper(*(p + i))) {
			a++;
		} else if (islower(*(p + i))) {
			b++;
		} else if (isspace(*(p + i))) {
			c++;
		} else if (isdigit(*(p + i))) {
			d++;
		} else {
			e++;
		}
	}
	
	cout << "��д��ĸ��" << a << "��" << endl;
	cout << "Сд��ĸ��" << b << "��" << endl;
	cout << "�ո���" << c << "��" << endl;
	cout << "������" << d << "��" << endl;
	cout << "�����ַ���" << e << "��" << endl;
	 
} 
