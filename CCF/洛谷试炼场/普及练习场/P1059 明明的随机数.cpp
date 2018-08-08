#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    set<int> record;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        record.insert(temp);
    }

    cout << record.size() << endl;
    for (auto iter = record.begin(); iter != record.end(); ++iter) {
        cout << *iter << " ";
    }
}
