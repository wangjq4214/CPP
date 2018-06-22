//第五章第8题
#include <iostream>

using namespace std;

int main() {
	int n, temp;
	cout << "请输入整数个数：";
	cin >> n;
	int sort[n];
	cout << "请输入按序排列的数据：" << endl;

	for (int i = 0; i < n; i++) {
		cin >> sort[i];
	}

	cout << "请输入要查找的数：";
	cin >> temp;

	if (temp < sort[0] || temp > sort[n - 1]) {
		cout << "无此数";
	} else {
		int str = 0, end = n - 1, mid;
		while (str < end) {
			mid = (str + end) / 2;
			if (temp < sort[mid]) {
				end = mid - 1;
			} else {
				str = mid + 1;
			}
		}
		if (sort[mid] == temp)
			cout << mid + 1;
		else
			cout << "无此数";


	}
}
