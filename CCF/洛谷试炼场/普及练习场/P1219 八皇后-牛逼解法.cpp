#include <iostream>

using namespace std;

int num, n, ans, tot, plan[15];

void dfs(int i, int c, int ld, int rd) {
    if (c == num) {
        if (++ans <= 3) {
            for (int i = 1; i < n; i++)
                cout << plan[i] << " ";
            cout << plan[n] << endl;
        }
        return;
    }
    int flag = num & ~(ld | rd | c);
    while (flag) {
        int p = flag & (-flag);
        flag -= p;
        plan[i] = __builtin_ffs(p);
        dfs(i + 1, c | p, (ld | p) << 1, (rd | p) >> 1);
    }
}

int main() {
    cin >> n;
    num = (1 << n) - 1;
    ans = 0;
    dfs(1, 0, 0, 0);
    cout << ans;
    return 0;
}
