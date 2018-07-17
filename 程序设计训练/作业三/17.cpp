#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    int sumz = 0, sumf = 0;
    for (int i = 0; i < n * 2; ++i) {
        cin >> x;
        if (i % 2 == 0) {
            if (x > 0) {
                sumz++;
            } else {
                sumf++;
            }
        }
        if (sumf > 1 && sumz > 1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
