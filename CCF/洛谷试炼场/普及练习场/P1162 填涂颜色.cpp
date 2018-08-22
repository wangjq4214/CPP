#include <bits/stdc++.h>

using namespace std;

int maze[35][35];
int use[35][35];

void findIt(int, int);

int main() {
    int n;
    cin >> n;

    memset(maze, 0, sizeof(maze));
    memset(use, 0, sizeof(use));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> maze[i][j];
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (maze[i][j] == 1) {
                findIt(i + 1, j + 1);
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

void findIt(int i, int j) {
    queue<pair<int, int> > temp;

    temp.push(make_pair(i, j));
    while (!temp.empty()) {
        int x = temp.front().first;
        int y = temp.front().second;
        temp.pop();
        maze[x][y] = 2;
        if (maze[x + 1][y] == 0 && use[x + 1][y] != 1) {
            temp.push(make_pair(x + 1, y));
            use[x + 1][y] = 1;
        }
        if (maze[x - 1][y] == 0 && use[x - 1][y] != 1) {
            temp.push(make_pair(x - 1, y));
            use[x - 1][y] = 1;
        }
        if (maze[x][y + 1] == 0 && use[x][y + 1] != 1) {
            temp.push(make_pair(x, y + 1));
            use[x][y + 1] = 1;
        }
        if (maze[x][y - 1] == 0 && use[x][y - 1] != 1) {
            temp.push(make_pair(x, y - 1));
            use[x][y - 1] = 1;
        }
    }
}
