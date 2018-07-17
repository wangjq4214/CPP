//第六章第5题
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int num, js = 0, i = 0;
	cout << "请输入人数：";
	cin >> num;
	int xulie[num];
	int k = num;
	int* p = xulie;
	memset(xulie, 0, sizeof(xulie));
	
	while (k != 1) {
		if (*(p + i) != 1) {
			js++;
		}
		if (js == 3) {
			*(p + i) = 1;
			k--;
			js = 0;
		}
		i++;
		if (i == num) {
			i = 0;
		}
	}
	i = 0;
	while (*(p + i) == 1) {
		i++;
	}
	
	cout << "最后一个人为" << i + 1 << "号"; 
}
