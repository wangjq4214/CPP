#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int> &x, const pair<int, int> &y) {
    return x.second > y.second;
}

int main() {
    map<int, int> num;
    vector<pair<int, int> > record;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        num[x]++;
    }
    for (map<int, int>::iterator iter = num.begin(); iter != num.end(); ++iter) {
        record.push_back(make_pair(iter->first, iter->second));
    }

    stable_sort(record.begin(), record.end(), compare);
    for (int i = 0; i < record.size(); ++i) {
        cout << record[i].first << " " << record[i].second << endl;
    }
}
