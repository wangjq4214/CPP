#include <iostream>

using namespace std;

void findIt(int, int, int &, int &, int *);

int main() {
    ios::sync_with_stdio(false);
    int n, sum = 0, total = 0;
    cin >> n;
    int record[n];
    findIt(n, 0, sum, total, record);
    cout << sum;
}

void findIt(int col, int num, int &sum, int &total, int *record) {
    if (num == col) {
        if (total < 3) {
            for (int i = 0; i < num; ++i) {
                cout << record[i] << " ";
            }
            cout << endl;
        }
        total++;
        sum++;
    } else {
        for (int i = 0; i < col; ++i) {
            bool flag = true;
            record[num] = i + 1;
            for (int j = 0; j < num; ++j) {
                if (record[j] == record[num] || num - record[num] == j - record[j] ||
                    num + record[num] == j + record[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                findIt(col, num + 1, sum, total, record);
            }
        }
    }
}
