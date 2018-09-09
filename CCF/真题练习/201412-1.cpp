#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    map<int, int> record;
    cin >> n;
    int store[n];
    for (int i = 0; i < n; ++i) {
        cin >> store[i];
    }

    for (int i = 0; i < n; ++i) {
        record[store[i]]++;
        cout << record[store[i]] << " ";
    }
}
