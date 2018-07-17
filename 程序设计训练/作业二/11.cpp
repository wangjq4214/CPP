#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> total;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        total.insert(x);
    }
    set<int>::iterator iter = total.begin();
    if (k > total.size()) {
        k = total.size();
    }
    for (int i = 0; i < k; ++i) {
        cout << *iter << " ";
        iter++;
    }
}
