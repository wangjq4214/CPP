#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, max, min;
    cin >> n;
    int store[n], jlc[n];

    for (int i = 0; i < n; ++i) {
        cin >> store[i];
    }
    max = min = store[0];

    for (int i = 1; i < n; ++i) {
        if (max < store[i]) {
            max = store[i];
        }
        if (min > store[i]) {
            min = store[i];
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        jlc[i] = abs(abs(store[i] - max) - (store[i] - min));
    }

    min = jlc[0];
    for (int i = 1; i < n; ++i) {
        if (min > jlc[i]) {
            min = jlc[i];
            count = i;
        } else if (min == jlc[i]) {
            if (store[i] < store[count]) {
                count = i;
            }
        }
    }

    cout << store[count];
}
