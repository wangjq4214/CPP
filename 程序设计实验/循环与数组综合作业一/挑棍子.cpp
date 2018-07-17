//ЬєЙїзг
#include <iostream>

using namespace std;

struct point {
	double x;
	double y;
	bool z;
};

double mult(point, point, point);

int main() {
	int num;

	while (1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		point sort[num][2];
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> sort[i][j].x;
				cin >> sort[i][j].y;
				sort[i][j].z = true; 
			}
		}

		for (int i = 0; i < num - 1; i++) {
			for (int j = i + 1; j < num; j++) {
				if (mult(sort[i][0], sort[i][1], sort[j][0]) * mult(sort[i][0], sort[i][1], sort[j][1]) <= 0 && mult(sort[j][0], sort[j][1], sort[i][0]) * mult(sort[j][0], sort[j][1], sort[i][1]) <= 0) {
					sort[i][0].z = sort[i][1].z = false;
					break;
				}
			}
		}
		cout << "Top sticks: ";
		for (int i = 0; i < num - 1; i++) {
			if (sort[i][0].z != false && sort[i][1].z != false) {
				cout << i + 1 << ",";
			}
		}
		cout << num;
		cout << endl;
	}
}

double mult(point a, point b, point c) {
	return (a.x-c.x) * (b.y-c.y) - (b.x-c.x) * (a.y-c.y);
}
