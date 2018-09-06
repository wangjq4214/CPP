#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rect;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        rect.push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int hight = rect[i];
        for (int j = i; j < n; ++j) {
            if (rect[j] < hight) {
                hight = rect[j];
            }
            int sum = (j - i + 1) * hight;
            if (ans < sum) {
                ans = sum;
            }
        }
    }
    cout << ans << endl;
}
