#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, l, t;
    cin >> n >> l >> t;
    int a[n], orientation[n];
    memset(orientation, 0, sizeof(orientation));

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (orientation[j] == 0 && a[j] != l) {
                a[j]++;
            }
            else if (orientation[j] == 1 && a[j] != 0) {
                a[j]--;
            }
            else if (orientation[j] == 0 && a[j] == l) {
                orientation[j] = 1;
                a[j] = l - 1;
            }
            else if (orientation[j] == 1 && a[j] == 0) {
                orientation[j] = 0;
                a[j] = 1;
            }
        }
        for (int j = 0; j < n ; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[j] == a[k]) {
                    int temp = orientation[j];
                    orientation[j] = orientation[k];
                    orientation[k] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}
