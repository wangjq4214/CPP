#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool table[n + 1];
    memset(table, true, sizeof(table));
    table[0] = table[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (table[i]) {
            for (int j = i * 2; j <= n; j += i) {
                table[j] = false;
            }
        }
    }

    bool flag = false;
    for (int i = 2; i <= n; ++i) {
        if (table[i]) {
            for (int j = 2; j <= n; ++j) {
                if (table[j]) {
                    for (int k = 2; k < n; ++k) {
                        if (table[k] && i + j + k == n) {
                            cout << i << " " << j << " " << k;
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) {
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
    }
}
