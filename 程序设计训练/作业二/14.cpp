#include <iostream>
#include <map>
#include <cstring>

using namespace std;

struct Record {
    int start;
    int len;

    Record() {
        start = 0;
        len = 0;
    }
};

int main() {
    int n, m, k;
    while (cin >> n >> m) {
        cin >> k;
        map<int, Record> record;
        bool mem[n * n];
        memset(mem, false, sizeof(mem));
        string str;
        int id, num;
        for (int i = 0; i < k; ++i) {
            cin >> str >> id;
            if (id > m) {
                cout << "no" << endl;
                continue;
            }
            if (str == "in") {
                cin >> num;
                if (record[id].len != 0) {
                    cout << "no" << endl;
                    continue;
                }
                bool flag = false;
                record[id].len = num;
                int count = 0;
                for (int j = 0; j < n * n + 1; ++j) {
                    if (count >= num) {
                        flag = true;
                        for (int l = 0; l < num; ++l) {
                            mem[record[id].start + l] = true;
                        }
                        cout << "yes" << endl;
                        break;
                    }
                    if (j == n * n) {
                        break;
                    }
                    if (mem[j]) {
                        count = 0;
                        record[id].start = j + 1;
                    } else {
                        count++;
                    }
                }
                if (!flag) {
                    for (map<int, Record>::iterator iter = record.begin(); iter != record.end(); ++iter) {
                        if (iter->first == id) {
                            record.erase(iter);
                            break;
                        }
                    }
                    cout << "no" << endl;
                }
            } else if (str == "out") {
                bool flag = false;
                for (map<int, Record>::iterator iter = record.begin(); iter != record.end(); ++iter) {
                    if (iter->first == id) {
                        for (int j = 0; j < iter->second.len; ++j) {
                            mem[iter->second.start + j] = false;
                        }
                        flag = true;
                        record.erase(iter);
                        cout << "yes" << endl;
                        break;
                    }
                }
                if (!flag) {
                    cout << "no" << endl;
                }
            }
        }
    }
}
