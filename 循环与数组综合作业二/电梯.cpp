//µçÌÝ 
#include <iostream>

using namespace std;

int main() {
	int num, sum = 0;
	cin >> num;
	int sort[num + 1];
	sort[0] = 0;
	for (int  i =1; i < num + 1; i++) {
		cin >> sort[i];
	}
	for (int i=0; i < num; i++) {
		if (sort[i] < sort[i+1]) {
			sum += (sort[i+1] - sort[i]) * 6;
		}
		if (sort[i] > sort[i+1]) {
			sum += (sort[i] - sort[i+1]) * 4;
		}
	}
	cout << sum + num * 5;
}

