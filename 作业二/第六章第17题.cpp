//第六章第17题
#include <iostream>
#include <string>

using namespace std;
int strcmp(char *p1, char *p2);

int main() {
	string s1, s2;
	cout << "请输入两个字符串：" << endl; 
	cin >> s1 >> s2;
	char *p1 = &s1[0], *p2 = &s2[0];
	cout <<"比较结果为：" << strcmp(p1, p2);
	return 0;
}

int strcmp(char *p1, char *p2) {
	int i = 0; 
	while (*p1 != '\0' && *p2 != '\0') {
		if (*p1 == *p2) {
			p1 += i;
			p2 += i;
		} else {
			return *p1 - *p2;
		}
		i++;
	}
}

