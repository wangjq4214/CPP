#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int figer[n];
    cin >> m;
    for (int i = 0; i < n; ++i) {
        cin >> figer[i];
    }

    for (int i = 0; i < m; ++i) {
        next_permutation(figer, figer + n);
    }

    for (int i = 0; i < n; ++i) {
        cout << figer[i] << " ";
    }
}
