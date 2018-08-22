#include <bits/stdc++.h>

using namespace std;

string A, B, A1, B1;
vector<pair<string, string> > record;
map<string, int> used;
queue<pair<string, int> > temp;

int findIt();

int main() {
    cin >> A >> B;
    while (cin >> A1 >> B1) {
        record.push_back(make_pair(A1, B1));
    }

    int sum = findIt();
    if (sum == -1) {
        cout << "NO ANSWER!";
    } else {
        cout << sum;
    }
}

int findIt() {
    temp.push(make_pair(A, 0));

    while (!temp.empty()) {
        string tempString = temp.front().first;
        int sum = temp.front().second;
        temp.pop();
        if (tempString == B) {
            return sum;
        } else if (sum > 10) {
            return -1;
        }

        for (int i = 0; i < record.size(); ++i) {
            string tempString1 = tempString;
            int sum1 = sum;
            int x = tempString1.find(record[i].first);
            if (x != -1) {
                tempString1.replace(x, record[i].first.size(), record[i].second);
                if (used[tempString1] == 0) {
                    sum1++;
                    temp.push(make_pair(tempString1, sum1));
                    used[tempString1] = 1;
                }
            }
        }
    }

    return -1;
}
