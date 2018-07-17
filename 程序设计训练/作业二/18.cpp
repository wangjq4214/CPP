#include <iostream>
#include <climits>

using namespace std;

int finding(const int [], int, int, int);

int main() {
    int n;
    cin >> n;
    int high[n];
    for (int i = 0; i < n; ++i) {
        cin >> high[i];
    }

    cout << finding(high, n, 0, INT_MAX);
}

int finding(const int high[], int n, int count, int temp) {
    if (count == n) {
        return 0;
    }
    if (high[count] <= temp) {
        return max(1 + finding(high, n, count + 1, high[count]), finding(high, n, count + 1, temp));
    } else {
        return finding(high, n, count + 1, temp);
    }
}
