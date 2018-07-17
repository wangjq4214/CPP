#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i < n; ++i) {
            if (n % i == 0) {
                sum1 += i;
            }
        }
        for (int i = 1; i < m; ++i) {
            if (m % i == 0) {
                sum2 += i;
            }
        }

        if (sum2 == n && sum1 == m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
