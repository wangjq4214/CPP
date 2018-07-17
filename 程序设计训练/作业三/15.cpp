#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bitset<2000> bit[n];
    for (int i = 0; i < n; ++i) {
        cin >> bit[i];
    }

    for (int i = 0; i < n; ++i) {
        bitset<2000> temp;
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            } else {
                temp = temp | bit[j];
                if (temp.count() == m) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    
    cout << "NO";
}
