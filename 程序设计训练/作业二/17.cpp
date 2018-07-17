#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

void findAndPrint(int, int, map<int, int>);

int main() {
    map<int, int> record;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        record[str[i] - '0']++;
    }

    while (cin >> str) {
        switch (str.size()) {
            case 1:
                findAndPrint(str[0] - '0', 1, record);
                break;
            case 2:
                findAndPrint(str[0] - '0', 2, record);
                break;
            case 3:
                findAndPrint(str[0] - '0', 3, record);
                break;
            case 4:
                findAndPrint(str[0] - '0', 4, record);
                break;
            case 5:
                bool mem[5];
                memset(mem, false, sizeof(mem));
                vector<int> store, store1;
                for (int i = 0; i < 5; ++i) {
                    bool flag = true;
                    int temp = 0;
                    for (int j = 1; j <= 5; ++j) {
                        temp = temp * 10 + i + j;
                        if (record[i + j] == 0) {
                            temp = 0;
                            flag = false;
                            break;
                        }
                    }
                    store.push_back(temp);
                    if (flag) {
                        mem[i] = true;
                    }
                }
                if (str[0] - '0' == 5) {
                    cout << "NO" << endl;
                } else {
                    for (int i = str[0] - '0'; i < 5; ++i) {
                        if (mem[i]) {
                            store1.push_back(store[i]);
                        }
                    }
                    if (store1.size()) {
                        cout << "YES";
                        for (int i = 0; i < store1.size(); ++i) {
                            cout << " " << store1[i];
                        }
                        cout << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                }
                break;
        }
    }
}

void findAndPrint(int x, int num, map<int, int> record) {
    vector<int> store;
    for (int i = x + 1; i < 10; ++i) {
        if (record[i] >= num) {
            int temp = 0;
            for (int j = 0; j < num; ++j) {
                temp = temp * 10 + i;
            }
            store.push_back(temp);
        }
    }
    if (store.size()) {
        cout << "YES";
        for (int i = 0; i < store.size(); ++i) {
            cout << " " << store[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
