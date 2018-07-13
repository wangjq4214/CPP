#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;
    while (cin >> n && n != 0) {
        string store[n];
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            if (i % 2 == 0) {
                store[i / 2] = str;
            } else {
                store[n - (i + 1) / 2] = str;
            }
        }
        cout << "set-" << ++sum << endl;
        for (int i = 0; i < n; ++i) {
            cout << store[i] << endl;
        }
    }
}
