#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(const string &x, const string &y) {
    return x + y > y + x;
}

int main() {
    int n;
    cin >> n;
    string record[n];

    for (int i = 0; i < n; ++i) {
        cin >> record[i];
    }

    sort(record, record + n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << record[i];
    }
}
