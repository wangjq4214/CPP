//第六章第15题
#include <iostream>
#include <string>
#include <cctype>

void find(char*);

using namespace std;

int main() {
	string str;
	cout << "请输入一个字符串：" << endl;
	getline(cin, str);
	char* p = &str[0];
	find (p);
	return 0; 
}

void find(char* pstr) {
	string str1[100];
	int i = 0;
	while (*pstr != '\0') {
		if (isdigit(*pstr)) {
			str1[i] += *pstr;
		} else if (isdigit(*(pstr + 1))) {
			i++;
		}
		pstr++;
	}
	cout << "共有" << i << "个整数";
	for (int j = 0; j <= i; j++) {
		cout << str1[j] << endl;
	} 
}
