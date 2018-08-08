#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    int record[n];

    for (int i = 0; i < n; ++i) {
        cin >> record[i];
    }

    sort(record, record + n);

    int sum = 0;
    int x = n - 1, y = 0;

    while (y <= x) {
        if (record[y] + record[x] <= w) {
            sum++;
            y++;
            x--;
        } else {
            x--;
            sum++;
        }
    }

    cout << sum;
}
