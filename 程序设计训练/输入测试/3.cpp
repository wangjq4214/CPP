#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int store[n + 1][m + 1];
    memset(store, 0, sizeof(store));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> store[i][j];
            store[i][m] += store[i][j];
        }
    }
    for (int i = 0; i < m + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            store[n][i] += store[j][i];
        }
    }

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            cout << store[i][j] << " ";
        }
        cout << endl;
    }
}
