#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

struct Edge {
    int from{0}, to{0}, weight{0};

    bool operator<(const Edge x) const {
        return weight > x.weight;
    }
};

int n, m;
int searchSet[MAXN]; // ���鼯
priority_queue<Edge> edge; // ���ȶ��� ����<���

void init();

int findIt(int); // ���鼯����
int Kruskal(); // ��С������

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        Edge temp;
        cin >> temp.from >> temp.to >> temp.weight;
        edge.push(temp);
    }
    init();

    cout << Kruskal();
}

void init() {
    // ��ʼ�����鼯
    for (int i = 0; i <= n; ++i) {
        searchSet[i] = i;
    }
}

int findIt(int x) {
    if (searchSet[x] == x) {
        return x;
    } else {
        int t = findIt(searchSet[x]);
        searchSet[x] = t;
        return t;
    }
}

int Kruskal() {
    int ans = 0;
    while (!edge.empty()) {
        Edge temp = edge.top();
        edge.pop();
        int x = findIt(temp.from);
        int y = findIt(temp.to);
        if (x != y) {
            searchSet[x] = y;
            ans += temp.weight;
        }
    }
    return ans;
}
