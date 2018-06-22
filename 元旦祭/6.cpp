//6
#include <iostream>
#include <queue>

using namespace std;

struct fruit {
		int z;
		fruit(int x) {
			z = x;
		}
};
bool operator <(const fruit &f1, const fruit &f2) {
	return f1.z > f2.z;
}

int main() {
	priority_queue<fruit> q;

	int n, y, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> y;
		q.push(fruit(y));
	}

	for (int i = 0; i < n - 1; i++) {
		int temp1 = q.top().z;
		q.pop();
		int temp2 = q.top().z;
		q.pop();
		sum = sum + temp1 + temp2;
		q.push(fruit(temp1 + temp2));
	}

	cout << sum;
}
