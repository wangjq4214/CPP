//�����µ�8��
#include <iostream>

using namespace std;

int main() {
	int n, temp;
	cout << "����������������";
	cin >> n;
	int sort[n];
	cout << "�����밴�����е����ݣ�" << endl;

	for (int i = 0; i < n; i++) {
		cin >> sort[i];
	}

	cout << "������Ҫ���ҵ�����";
	cin >> temp;

	if (temp < sort[0] || temp > sort[n - 1]) {
		cout << "�޴���";
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
			cout << "�޴���";


	}
}
