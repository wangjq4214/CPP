#include <bits/stdc++.h>

using namespace std;

int main() {
    int status, n;
    string strB, strS;
    cin >> strB;
    transform(strB.begin(), strB.end(), strS.begin(), ::tolower);
    cin >> status;
    cin >> n;
    string record[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> record[i][0];
        transform(record[i][0].begin(), record[i][0].end(), record[i][1].begin(), ::tolower);
    }
    switch (status) {
        case 0:
            for (int i = 0; i < n; ++i) {
                if (record[i][1].find(strS) != -1) {
                    cout << record[i][0] << endl;
                }
            }
            break;
        case 1:
            for (int i = 0; i < n; ++i) {
                if (record[i][0].find(strB) != -1) {
                    cout << record[i][0] << endl;
                }
            }
            break;
    }
}
