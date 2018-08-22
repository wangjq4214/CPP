#include <bits/stdc++.h>

using namespace std;

const string ZHENG = "yizhong";
const string FAN = "gnohziy";
int biaoJi[110][110];
string str[110];

void findIt(int, int, int);

int main() {
    int n;
    cin >> n;

    memset(biaoJi, 0, sizeof(biaoJi));
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (str[i][j] == 'y' || str[i][j] == 'g') {
                findIt(n, i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (biaoJi[i][j]) {
                cout << str[i][j];
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void findIt(int n, int i, int j) {
    string temp;
    if (n - i >= 7 && n - j >= 7) {
        for (int k = 0; k < 7; ++k) {
            temp += str[i + k][j + k];
        }
        if (temp == ZHENG || temp == FAN) {
            for (int k = 0; k < 7; ++k) {
                biaoJi[i + k][j + k] = 1;
            }
        }
    }
    if (i >= 6 && j >= 6) {
        temp.clear();
        for (int k = 0; k < 7; ++k) {
            temp += str[i - k][j - k];
        }
        if (temp == ZHENG || temp == FAN) {
            for (int k = 0; k < 7; ++k) {
                biaoJi[i - k][j - k] = 1;
            }
        }
    }
    if (n - i >= 7) {
        temp.clear();
        for (int k = 0; k < 7; ++k) {
            temp += str[i + k][j];
        }
        if (temp == ZHENG || temp == FAN) {
            for (int k = 0; k < 7; ++k) {
                biaoJi[i + k][j] = 1;
            }
        }
    }
    if (n - j >= 7) {
        temp.clear();
        for (int k = 0; k < 7; ++k) {
            temp += str[i][j + k];
        }
        if (temp == ZHENG || temp == FAN) {
            for (int k = 0; k < 7; ++k) {
                biaoJi[i][j + k] = 1;
            }
        }
    }
}
