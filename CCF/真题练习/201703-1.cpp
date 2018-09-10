#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, sum = 0, count = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        if (sum >= k && i != n - 1) {
            sum = 0;
            count++;
        }
    }
    cout << count + 1;
}
