#include<iostream>
#include<algorithm>

using namespace std;

struct Stu {
    int num;//±àºÅ
    int c, m, e;
    int sum;
};

bool compare(const Stu &x, const Stu &y) {
    if (x.sum == y.sum && x.c == y.c) {
        return x.num < y.num;
    }
    if (x.sum == y.sum) {
        return x.c > y.c;
    }
    return x.sum > y.sum;
}

int main() {
    int n;
    cin >> n;
    Stu stu[n];
    for (int i = 0; i < n; i++) {
        stu[i].num = i + 1;
        cin >> stu[i].c >> stu[i].m >> stu[i].e;
        stu[i].sum = stu[i].c + stu[i].m + stu[i].e;
    }
    sort(stu, stu + n, compare);
    for (int i = 0; i < 5; i++)
        cout << stu[i].num << ' ' << stu[i].sum << endl;
    return 0;
}
