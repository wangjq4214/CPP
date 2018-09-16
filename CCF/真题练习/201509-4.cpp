#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;
long long ans = 0;
int n, m;
int dfsClock[MAXN];
int low[MAXN];
int inStack[MAXN];
int visited[MAXN];
stack<int> dfsStack;
vector<int> graph[MAXN];

void init();

void scc(int);

int main() {
    init();

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            visited[i] = 1;
            scc(i);
        }
    }

    cout << ans << endl;
}

void init() {
    memset(dfsClock, 0, sizeof(dfsClock));
    memset(low, 0, sizeof(low));
    memset(inStack, 0, sizeof(inStack));
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
}

void scc(int x) {
    static int count = 0;
    dfsClock[x] = low[x] = ++count;
    dfsStack.push(x);
    inStack[x] = 1;

    for (int i = 0; i < graph[x].size(); ++i) {
        int next = graph[x][i];
        if (visited[next] == 0) {
            visited[next] = 1;
            scc(next);
            low[x] = min(low[x], low[next]);
        } else if (inStack[x] == 1) {
            low[x] = min(low[x], dfsClock[next]);
        }
    }

    if (dfsClock[x] == low[x]) {
        int sum = 0, y;
        do {
            y = dfsStack.top();
            dfsStack.pop();
            inStack[y] = 0;
            sum++;
        } while (x != y);
        ans += (sum - 1) * sum / 2;
    }
}
