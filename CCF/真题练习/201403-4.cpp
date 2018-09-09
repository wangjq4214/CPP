#include <bits/stdc++.h>

using namespace std;

const int MAXN = 210;
int n, m, k, r;
struct Point {
    int step{0}, count{0};
    double x{}, y{};
    bool status = false;
} point[MAXN];

int findIt();

int main() {
    cin >> n >> m >> k >> r;

    for (int i = 0; i < n + m; ++i) {
        cin >> point[i].x >> point[i].y;
    }

    int ans = findIt();

    cout << ans;
}

int findIt() {
    queue<Point> record;

    point[0].status = true;
    record.push(point[0]);
    while (!record.empty()) {
        Point temp = record.front();
        record.pop();

        if (temp.x == point[1].x && temp.y == point[1].y) {
            return temp.step - 1;
        }

        for (int i = 0; i < (temp.count == k ? n : m + n); ++i) {
            if (((temp.x - point[i].x) * (temp.x - point[i].x) + (temp.y - point[i].y) * (temp.y - point[i].y)) <=
                r * r && !point[i].status) {
                point[i].status = true;
                point[i].step = temp.step + 1;
                if (i >= n) {
                    point[i].count = temp.count + 1;
                } else {
                    point[i].count = temp.count;
                }
                record.push(point[i]);
            }
        }
    }

    return 0;
}
