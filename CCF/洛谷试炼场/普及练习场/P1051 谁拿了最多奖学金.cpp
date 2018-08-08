#include <iostream>
#include <algorithm>

using namespace std;

struct Stu {
    int prize;
    string name;

    Stu() {
        prize = 0;
    }
};

bool compare(const Stu &x, const Stu &y) {
    return x.prize > y.prize;
}

int main() {
    int n, sum = 0;
    cin >> n;
    Stu stu[n];
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].name;
        int finalScore, classScore, page;
        char worker, east;
        cin >> finalScore >> classScore >> worker >> east >> page;
        if (finalScore > 80 && page > 0) {
            stu[i].prize += 8000;
            sum += 8000;
        }
        if (finalScore > 85 && classScore > 80) {
            stu[i].prize += 4000;
            sum += 4000;
        }
        if (finalScore > 90) {
            stu[i].prize += 2000;
            sum += 2000;
        }
        if (east == 'Y' && finalScore > 85) {
            stu[i].prize += 1000;
            sum += 1000;
        }
        if (classScore > 80 && worker == 'Y') {
            stu[i].prize += 850;
            sum += 850;
        }
    }

    stable_sort(stu, stu + n, compare);

    cout << stu[0].name << endl << stu[0].prize << endl << sum;
}
