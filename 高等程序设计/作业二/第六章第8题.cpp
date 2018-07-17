//第六章第8题
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	cout << "请输入一个字符串：" ;
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
	
	cout << "大写字母有" << a << "个" << endl;
	cout << "小写字母有" << b << "个" << endl;
	cout << "空格有" << c << "个" << endl;
	cout << "数字有" << d << "个" << endl;
	cout << "其他字符有" << e << "个" << endl;
	 
} 
