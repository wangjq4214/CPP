#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 1;
    cin >> n;
    int temp[n];
    cin >> temp[0];
    for (int i = 1; i < n; ++i) {
        cin >> temp[i];
        if (temp[i] != temp[i - 1]) {
            sum++;
        }
    }
    cout << sum;
}
