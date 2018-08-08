#include <iostream>
#include <algorithm>

using namespace std;

struct Line {
    int x;
    int y;
};

bool compare(const Line &x, const Line &y) {
    return x.y < y.y;
}

int main() {
    int n;
    cin >> n;
    Line line[n];

    for (int i = 0; i < n; ++i) {
        cin >> line[i].x;
        cin >> line[i].y;
    }

    sort(line, line + n, compare);

    int sum = 1;
    int end = line[0].y;
    for (int i = 1; i < n; ++i) {
        if (line[i].x >= end) {
            sum++;
            end = line[i].y;
        }
    }

    cout << sum;
}
