#include <iostream>

using namespace std;

int win[][3] = {
	1, 0, 2,
	2, 1, 0,
	0, 2, 1
};

int win2[] = {
	3, 0, 1, 3, 3, 3, 3, 3, 3, 2
};

int main() {
	int N;
	cin >> N;
	char jia, yi;
	int sum1[3][3] = {0};
	int sum2[3][3] = {0};
	for (int i = 0; i < N; ++i) {
		cin >> jia >> yi;
		sum1[win2[jia - 'A']][win[win2[jia - 'A']][win2[yi - 'A']]]++;
		sum2[win2[yi - 'A']][win[win2[yi - 'A']][win2[jia - 'A']]]++;
	}

	cout << sum1[0][0] + sum1[1][0] + sum1[2][0] << " "
	     << sum1[0][1] + sum1[1][1] + sum1[2][1] << " "
	     << sum1[0][2] + sum1[1][2] + sum1[2][2] << endl;
	cout << sum2[0][0] + sum2[1][0] + sum2[2][0] << " "
	     << sum2[0][1] + sum2[1][1] + sum2[2][1] << " "
	     << sum2[0][2] + sum2[1][2] + sum2[2][2] << endl;
	
	if (sum1[0][0] >= sum1[1][0] && sum1[0][0] >= sum1[2][0]) {
		cout << "B";
	} else if (sum1[1][0] >= sum1[0][0] && sum1[1][0] >= sum1[2][0]) {
		cout << "C";
	} else {
		cout << "J";
	}
	cout << " ";
	if (sum2[0][0] >= sum2[1][0] && sum2[0][0] >= sum2[2][0]) {
		cout << "B";
	} else if (sum2[1][0] >= sum2[0][0] && sum2[1][0] >= sum2[2][0]) {
		cout << "C";
	} else {
		cout << "J";
	}
}
