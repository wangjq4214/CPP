#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    vector<int> temp;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        temp.push_back(i);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num, count;
        cin >> num >> count;

        vector<int>::iterator iter = find(temp.begin(), temp.end(), num);
        int x = *iter;
        if (count > 0) {
            temp.insert(iter + count + 1, x);
            temp.erase(iter);
        } else {
            temp.insert(iter + count, x);
            temp.erase(iter + 1);
        };
    }

    for (int i = 1; i <= n; ++i) {
        cout << temp[i] << " ";
    }
}
