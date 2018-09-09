#include <bits/stdc++.h>

using namespace std;
const int N = 1000 + 10;
int a[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n - 1; i++)
            cout << a[i][j] << " ";
        cout << a[n - 1][j] << endl;
    }
    return 0;
}
