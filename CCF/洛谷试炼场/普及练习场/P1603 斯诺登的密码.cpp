#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> record;

void setValue();

int main() {
    setValue();
    string str;
    vector<int> store;
    for (int i = 0; i < 6; ++i) {
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        store.push_back((record[str] * record[str]) % 100);
    }


    sort(store.begin(), store.end());
    long long x = 0;
    for (int i = 0; i < store.size(); ++i) {
        x = x * 100 + store[i];
    }

    cout << x;
}

void setValue() {
    record["one"] = 1;
    record["two"] = 2;
    record["three"] = 3;
    record["four"] = 4;
    record["five"] = 5;
    record["six"] = 6;
    record["seven"] = 7;
    record["eight"] = 8;
    record["nine"] = 9;
    record["ten"] = 10;
    record["eleven"] = 11;
    record["twelve"] = 12;
    record["thirteen"] = 13;
    record["fourteen"] = 14;
    record["fifteen"] = 15;
    record["sixteen"] = 16;
    record["seventeen"] = 17;
    record["eighteen"] = 18;
    record["nineteen"] = 19;
    record["twenty"] = 20;
    record["a"] = 1;
    record["both"] = 2;
    record["another"] = 1;
    record["first"] = 1;
    record["second"] = 2;
    record["third"] = 3;
}
