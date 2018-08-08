#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, pair<int, int> > record;
    int x, y, time, temp, sum = 0;
    cin >> x >> y >> time;

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            cin >> temp;
            if (temp != 0) {
                record[temp] = make_pair(i, j);
            }
        }
    }
    temp = record.rbegin()->second.first * 2 + 1;
    if (time >= temp) {
        time -= (record.rbegin()->second.first + 1);
        sum += record.rbegin()->first;
    } else {
        cout << sum;
        return 0;
    }
    for (auto iter = record.rbegin(); iter != --record.rend(); ++iter) {
        auto iter1 = ++iter;
        iter--;
        temp = abs(iter->second.first - iter1->second.first) + abs(iter->second.second - iter1->second.second) + 1 +
               iter1->second.first;
        if (time >= temp) {
            time -= (abs(iter->second.first - iter1->second.first) + abs(iter->second.second - iter1->second.second) +
                     1);
            sum += iter1->first;
        } else {
            break;
        }
    }

    cout << sum;
}
