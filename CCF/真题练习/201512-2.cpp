#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int temp[n][m];
    bool index[n][m];
    memset(index, false, sizeof(index));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (temp[i][j - 1] == temp[i][j] && temp[i][j + 1] == temp[i][j]) {
                index[i][j - 1] = index[i][j] = index[i][j + 1] = true;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n - 1; i++) {
            if (temp[i - 1][j] == temp[i][j] && temp[i + 1][j] == temp[i][j]) {
                index[i - 1][j] = index[i][j] = index[i + 1][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (index[i][j]) {
                temp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << temp[i][j] << " ";
        }
        cout << temp[i][m - 1] << endl;
    }
    return 0;
}
