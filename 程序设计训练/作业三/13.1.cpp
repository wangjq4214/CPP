#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, sum, total = 0;
    cin >> n >> sum;
    int storage[sum] = {0};

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (str == "alloc") {
            int len;
            cin >> len;
            auto pos = search_n(storage, storage + sum, len, 0);
            if (pos != storage + sum) {
                replace(pos, pos + len, 0, ++total);
                cout << total << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else if (str == "erase") {
            int number;
            cin >> number;
            auto pos = find(storage, storage + sum, number);
            if (pos != storage + sum) {
                replace(storage, storage + sum, number, 0);
            } else {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (str == "defragment") {
            stable_sort(storage, storage + sum, greater<int>());
        }
    }
}
