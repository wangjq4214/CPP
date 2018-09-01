#include <bits/stdc++.h>

using namespace std;

int n, m, sx, sy;

const int dx[] = {-1, 1, -2, 2};
const int dy[] = {-1, 1, -2, 2};

struct Node {
    int position;
    bool used;

    Node() {
        position = -2;
        used = false;
    }
} node[410][410];

void findIt();

int main() {
    cin >> n >> m >> sx >> sy;

    for (int i = 2; i < n + 2; ++i) {
        for (int j = 2; j < m + 2; ++j) {
            node[i][j].position = -1;
        }
    }

    findIt();

    for (int i = 2; i < n + 2; ++i) {
        for (int j = 2; j < m + 2; ++j) {
            cout << setw(5) << left << node[i][j].position;
        }
        cout << endl;
    }
}

void findIt() {
    queue<pair<int, int> > temp;
    node[sx + 1][sy + 1].position = 0;
    node[sx + 1][sy + 1].used = true;
    temp.push(make_pair(sx + 1, sy + 1));

    while (!temp.empty()) {
        int x = temp.front().first;
        int y = temp.front().second;
        temp.pop();
        int sum = node[x][y].position;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (abs(dx[i]) != abs(dy[j])) {
                    if (node[x + dx[i]][y + dy[j]].position != -2 &&
                        !node[x + dx[i]][y + dy[j]].used) {
                        temp.push(make_pair(x + dx[i], y + dy[j]));
                        node[x + dx[i]][y + dy[j]].position = sum + 1;
                        node[x + dx[i]][y + dy[j]].used = true;
                    }
                }
            }
        }
    }
}
