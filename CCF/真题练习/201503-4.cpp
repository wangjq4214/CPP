#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    queue<int> record;
    cin >> n >> m;
    int graph[n + m + 1][n + m + 1];
    int rank[n + m + 1];
    bool visit[n + m + 1];
    memset(graph, 0, sizeof(graph));
    memset(rank, 0, sizeof(rank));
    memset(visit, false, sizeof(visit));

    for (int i = 2; i <= n + m; ++i) {
        int x;
        cin >> x;
        graph[i][x] = 1;
        graph[x][i] = 1;
    }

    record.push(1);
    visit[1] = true;
    int x;
    while (!record.empty()) {
        x = record.front();
        record.pop();
        for (int i = 1; i <= n + m; ++i) {
            if (graph[x][i] == 1 && !visit[i]) {
                record.push(i);
                visit[i] = true;
            }
        }
    }

    memset(visit, false, sizeof(visit));
    record.push(x);
    visit[x] = true;

    while (!record.empty()) {
        x = record.front();
        record.pop();
        for (int i = 1; i <= n + m; ++i) {
            if (graph[x][i] == 1 && !visit[i]) {
                record.push(i);
                visit[i] = true;
                rank[i] = rank[x] + 1;
            }
        }
    }

    cout << rank[x];
}
