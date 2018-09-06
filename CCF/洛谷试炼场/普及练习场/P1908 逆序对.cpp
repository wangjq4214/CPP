#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50000;
int n, readIn[MAXN] = {0}, liSan[MAXN] = {0}, tree[MAXN] = {0};

// 离散化排序方式
bool compare(const int &x, const int &y) {
    return readIn[x] > readIn[y];
}

// 加入树状数组
void join(int);

// 求和操作
int sum(int);

int main() {
    ios::sync_with_stdio(false);
    int ans = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> readIn[i];
        liSan[i] = i;
    }
    // 数据离散化
    sort(liSan + 1, liSan + n + 1, compare);

    for (int i = 1; i <= n; ++i) {
        join(liSan[i]);
        ans += sum(liSan[i] - 1);
    }

    cout << ans;
}

void join(int x) {
    for (x; x <= n; x += (x & -x)) {
        tree[x]++;
    }
}

int sum(int x) {
    int s = 0;
    for (x; x > 0; x -= (x & -x)) {
        s += tree[x];
    }
    return s;
}
