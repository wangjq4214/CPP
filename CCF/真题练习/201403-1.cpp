#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10;
int a[N], n;

int main() {
    memset(a, 0, sizeof(a));
    int ans = 0, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        v = abs(v);
        a[v]++;
        if (a[v] == 2)
            ans++; //��һ���෴��
    }
    cout << ans;
    return 0;
}
