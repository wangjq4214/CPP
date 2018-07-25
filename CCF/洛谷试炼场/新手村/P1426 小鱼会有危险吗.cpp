#include <iostream>

using namespace std;

int main() {
    int s, x;
    cin >> s >> x;

    int start = s - x, end = s + x;

    double distance = 0, ax = 7;
    while (distance < start) {
        distance += ax;
        ax *= 0.98;
    }

    if (distance + ax * 0.98 > end) {
        cout << "n";
    } else {
        cout << "y";
    }
}
