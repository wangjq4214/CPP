#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Teen {
    int num;
    int score;
};

bool compare(const Teen &x, const Teen &y) {
    if (x.score == y.score) {
        return x.num < y.num;
    }
    return x.score > y.score;
}

int main() {
    int n, m;
    cin >> n >> m;
    Teen teen[n];
    for (int i = 0; i < n; ++i) {
        cin >> teen[i].num;
        cin >> teen[i].score;
    }

    sort(teen, teen + n, compare);
    m = static_cast<int>(floor(m * 1.5));

    int i = 0, count = 0;
    while (teen[i].score >= teen[m].score) {
        count++;
        i++;
    }
    cout << teen[m].score << " " << count << endl;
    for (int j = 0; j < count; ++j) {
        cout << teen[j].num << " " << teen[j].score << endl;
    }
}
