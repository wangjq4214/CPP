#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int temp[n];
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    sort(temp, temp + n);

    int l, r, ans = -1;
    l = r = n / 2;
    while (temp[l - 1] == temp[l]) {
        l--;
    }
    while (temp[r + 1] == temp[r]) {
        r++;
    }
    if (l == n - r - 1) {
        ans = temp[l];
    }
    cout << ans;
    return 0;
}
