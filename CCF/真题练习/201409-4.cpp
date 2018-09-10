#include <bits/stdc++.h>

using namespace std;

int n, m, k, d; // 方格图的大小 分店数量 客户数量 不能经过的点数量
int direct[][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // 方向数组
struct Point {
    int x, y;
    int orderNum{0}, step{0}; // 订餐数量 步数
    bool visited{false}; // false为路、顾客 true为商户、阻碍
} point[1010][1010];

queue<Point> record;

void input();

void findIt();

int main() {
    input();
    findIt();
}

void input() {
    cin >> n >> m >> k >> d;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        point[x][y].x = x;
        point[x][y].y = y;
        point[x][y].visited = true;
        record.push(point[x][y]);
    }
    for (int i = 0; i < k; ++i) {
        int x, y, num;
        cin >> x >> y >> num;
        point[x][y].orderNum += num;
    }
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        point[x][y].visited = true;
    }
}

void findIt() {
    long long ans = 0;
    while (!record.empty()) {
        Point temp = record.front();
        record.pop();
        for (int i = 0; i < 4; ++i) {
            int now_x = temp.x + direct[i][0];
            int now_y = temp.y + direct[i][1];
            if (now_x > 0 && now_x <= n && now_y > 0 && now_y <= n) {
                if (!point[now_x][now_y].visited) {
                    if (point[now_x][now_y].orderNum != 0) {
                        ans += point[now_x][now_y].orderNum * (temp.step + 1);
                        point[now_x][now_y].step = temp.step + 1;
                        point[now_x][now_y].visited = true;
                        point[now_x][now_y].x = now_x;
                        point[now_x][now_y].y = now_y;
                        record.push(point[now_x][now_y]);
                    } else {
                        point[now_x][now_y].step = temp.step + 1;
                        point[now_x][now_y].visited = true;
                        point[now_x][now_y].x = now_x;
                        point[now_x][now_y].y = now_y;
                        record.push(point[now_x][now_y]);
                    }
                }
            }
        }
    }

    cout << ans;
}
