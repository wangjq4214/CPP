#include <bits/stdc++.h>

using namespace std;
int n, m, t;
int sx, sy, fx, fy;
int maze[10][10];

void findIt(int &, int, int);

int main() {
    int sum = 0;
    cin >> n >> m >> t;

    memset(maze, 1, sizeof(maze));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            maze[i][j] = 0;
        }
    }

    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
    }

    findIt(sum, sx, sy);
    cout << sum;
}

void findIt(int &sum, int x, int y) {
    if (x == fx && y == fy && maze[x][y] == 0) {
        sum++;
        return;
    }
    if (maze[x][y]) {
        return;
    } else {
        maze[x][y] = 1;
        findIt(sum, x + 1, y);
        findIt(sum, x - 1, y);
        findIt(sum, x, y + 1);
        findIt(sum, x, y - 1);
        maze[x][y] = 0;
    }
}
