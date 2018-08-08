#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m = 0, sum = 0, ans = 0, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (sum + x <= m) {
            sum += x;
        } else {
            ans++;
            sum = x;
        }
    }
    cout << ans + 1;
    return 0;
}
