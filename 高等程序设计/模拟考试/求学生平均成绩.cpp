//求学生平均成绩
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int num;
	cin >> num;
	string str[num];
	double sort[num][5];
	
	for (int i = 0; i < num; i++) {
		cin >> str[i];
		for (int j = 1; j < 4; j++) {
			cin >> sort[i][j];
		}
	}
	
	for (int i = 0; i < num; i++) {
		sort[i][4] = (sort[i][1] + sort[i][2] + sort[i][3]) / 3;
		cout << str[i] << " " << sort[i][4] << endl;
	}
}
