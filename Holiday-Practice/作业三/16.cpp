#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &x, const string &y) {
    if (x.size() == y.size()) {
        return x < y;
    } else {
        return x.size() < y.size();
    }

}

int main() {
    int n;
    cin >> n;
    map<string, vector<string> > record;
    for (int i = 0; i < n; ++i) {
        string name, phone;
        int num;
        cin >> name;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            cin >> phone;
            bool flag = false;
            for (int k = 0; k < record[name].size(); ++k) {
                if (phone == record[name][k]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                record[name].push_back(phone);
            }
        }
    }


    cout << record.size() << endl;
    for (map<string, vector<string> >::iterator iter = record.begin(); iter != record.end(); ++iter) {
        sort(iter->second.begin(), iter->second.end(), comp);
        int sum = iter->second.size();
        for (vector<string>::iterator iterSet = iter->second.begin(); iterSet != --(iter->second.end()); ++iterSet) {
            regex r("^[0-9]+" + *iterSet + "$");
            for (vector<string>::iterator iterSet1 = iterSet; iterSet1 != iter->second.end(); ++iterSet1) {
                if (iterSet == iterSet1) {
                    continue;
                } else {
                    if (regex_match(*iterSet1, r)) {
                        sum--;
                        *iterSet = "";
                        break;
                    }
                }
            }
        }
        cout << iter->first << " " << sum << " ";
        for (vector<string>::iterator iterSet = iter->second.begin(); iterSet != iter->second.end(); ++iterSet) {
            if (*iterSet != "") {
                cout << *iterSet << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
