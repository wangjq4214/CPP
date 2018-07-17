//¿¼ÑÐÂ·Ã£Ã£
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double jingdu = 1e-8;

struct point {
	double x;
	double y;
};

double gouzao(double, double, point, int);
double caozuo(point, point, int);

int main() {
	int m, n;
	cin >> m >> n;
	point poin[m];
	for (int i = 0; i < m; i++) {
		cin >> poin[i].x >> poin[i].y;
	}
	
	double min1 = caozuo(poin[0], poin[1], n);
	
	for (int i = 1; i < m - 1; i++) {
		double min2 = caozuo(poin[i], poin[i + 1], n);
		if (min2 < min1) {
			min1 = min2;
		}
	}
	
	cout << fixed << setprecision(2) << min1;
}

double caozuo(point p1, point p2, int n) {
	double k = (p1.y - p2.y) / (p1.x - p2.x);
	double left = p1.x;
	double right = p2.x;
	double mid = left + (right - left) / 3;
	double mmid = right - (right - left) / 3;
	while (right - left > jingdu) {
		if (gouzao(mid, k, p1, n) > gouzao(mmid, k, p1, n)) {
			left = mid;
			mid = left + (right - left) / 3;
			mmid = right - (right - left) / 3;
		} else {
			right = mmid;
			mid = left + (right - left) / 3;
			mmid = right - (right - left) / 3;
		}
	}
	
	return gouzao(right, k, p1, n);
}

double gouzao(double x, double k, point p1, int n) {
	return (n / pow(x, 2)) + (k * (x - p1.x) + p1.y);
}
