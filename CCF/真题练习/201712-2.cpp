#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> record;
    for (int i = 1; i <= n; ++i) {
        record.push(i);
    }

    int count = 1;
    while (record.size() != 1) {
        int temp = record.front();
        record.pop();
        if (count % k != 0 && count % 10 != k) {
            record.push(temp);
        }
        count++;
    }
    cout << record.front();
}
