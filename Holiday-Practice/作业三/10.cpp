#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int temp[n], store[n][n];
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); ++j) {
            store[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (store[i][j]) {
                int x = min(n - i, n - j);
                for (int k = 1; k <= x; ++k) {
                    bool flag = true;
                    for (int l = 0; l < k; ++l) {
                        for (int m = 0; m < k; ++m) {
                            if (store[i + l][j + m] == (l + m) % 2) {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) {
                            break;
                        }
                    }
                    if (flag) {
                        temp[k - 1]++;
                    }
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (temp[i] != 0) {
            cout << i + 1 << " " << temp[i];
            break;
        }
    }
}
