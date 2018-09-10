#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int a[1005];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 100000;
    for (int i = 1; i < n; i++)
        if (ans > a[i] - a[i - 1])
            ans = a[i] - a[i - 1];
    cout << ans;
    return 0;
}
