#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

struct Storage {
    int num;
    int start;
    int length;
};

bool comp(const Storage &x, const Storage &y) {
    return x.start < y.start;
}

int main() {
    int t, m;
    cin >> t >> m;
    cin.get();
    vector<Storage> storage;
    bool mem[m];
    memset(mem, true, sizeof(mem));
    int sum = 0;
    for (int i = 0; i < t; ++i) {
        string str;
        getline(cin, str);
        if (str == "defragment") {
            // 整理内存
            memset(mem, true, sizeof(mem));
            sort(storage.begin(), storage.end(), comp);
            int k = 0;
            for (int j = 0; j < storage.size(); ++j) {
                storage[j].start = k;
                for (int l = 0; l < storage[j].length; ++l) {
                    mem[k++] = false;
                }
            }
        } else {
            // 分词
            vector<string> temp;
            string str1;
            for (int j = 0; j < str.size(); ++j) {
                if (str[j] == ' ') {
                    temp.push_back(str1);
                    str1.clear();
                } else {
                    str1 += str[j];
                }
            }
            temp.push_back(str1);
            // 转化文本
            int x;
            stringstream sstr;
            sstr << temp[1];
            sstr >> x;
            // 进行操作
            if (temp[0] == "alloc") {
                bool flag = true;
                Storage tempStorage;
                int count = 0;
                tempStorage.length = x;
                tempStorage.start = 0;
                for (int j = 0; j < m + 1; ++j) {
                    if (count >= x) {
                        flag = false;
                        tempStorage.num = ++sum;
                        cout << sum << endl;
                        storage.push_back(tempStorage);
                        for (int k = 0; k < tempStorage.length; ++k) {
                            mem[tempStorage.start + k] = false;
                        }
                        break;
                    }
                    if (j == m) {
                        break;
                    }
                    if (!mem[j]) {
                        tempStorage.start = j + 1;
                        count = 0;
                    } else {
                        count++;
                    }
                }
                if (flag) {
                    cout << "NULL" << endl;
                }
            } else if (temp[0] == "erase") {
                bool flag = true;
                for (vector<Storage>::iterator iter = storage.begin();
                     iter != storage.end() && storage.size() != 0; ++iter) {
                    if (iter->num == x) {
                        flag = false;
                        for (int k = 0; k < iter->length; ++k) {
                            mem[iter->start + k] = true;
                        }
                        storage.erase(iter);
                        break;
                    }
                }
                if (flag) {
                    cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
                }
            }
        }
    }
}
