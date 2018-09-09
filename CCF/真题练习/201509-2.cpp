#include <bits/stdc++.h>

using namespace std;

int day[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                 {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int leap(int);

int main() {
    int yyyy, count;
    cin >> yyyy;
    cin >> count;

    int index = leap(yyyy);

    for (int i = 0; i < 12; ++i) {
        if (count - day[index][i] <= 0) {
            cout << i + 1 << endl << count;
            return 0;
        } else {
            count -= day[index][i];
        }
    }
}

int leap(int yyyy) {
    if ((yyyy % 4 == 0 && yyyy % 100 != 0) || yyyy % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}
