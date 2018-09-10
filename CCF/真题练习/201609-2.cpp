#include <bits/stdc++.h>

using namespace std;

int main() {
    bitset<5> record[20];
    int n;
    cin >> n;

    while (n--) {
        int x, count = 0;
        cin >> x;
        bool flag = false;
        for (int i = 0; i < 20; ++i) {
            if (x <= 5 - record[i].count()) {
                flag = true;
                for (int j = 0; j < 5; ++j) {
                    if (count != x && record[i][j] == false) {
                        count++;
                        record[i][j] = true;
                        cout << i * 5 + j + 1 << " ";
                    }
                }
                cout << endl;
                break;
            }
        }
        if (!flag) {
            for (int i = 0; i < 20; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (count == x) {
                        flag = true;
                        break;
                    }
                    if (record[i][j] == false) {
                        count++;
                        record[i][j] = true;
                        cout << i * 5 + j + 1 << " ";
                    }
                }
                if (flag) {
                    break;
                }
            }
            cout << endl;
        }

    }
}
