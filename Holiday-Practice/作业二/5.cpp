#include <iostream>
#include <vector>

using namespace std;

vector<int> find(int, vector<int>, vector<int>);

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> store, res;
        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            int x;
            cin >> x;
            store.push_back(x);
        }

        // 排除特殊
        if (store.size() == 1) {
            cout << "1 1";
        } else {
            // 记录初始量
            int y = store[0];
            int z = store[1];
            vector<int> store1(store);
            // 进行枚举
            for (int i = 1; i <= y / 2; ++i) {
                // 枚举res[0]res[1]res[2]
                res.clear();
                store = store1;
                res.push_back(i);
                res.push_back(y - i);
                res.push_back(z - i);
                store[0] = 0;
                // 递归调用
                res = find(n, store, res);
                if (res.size()) {
                    for (int j = 0; j < res.size(); ++j) {
                        cout << res[j] << " ";
                    }
                    break;
                }
            }
        }
        cout << endl;
    }
}

vector<int> find(int n, vector<int> store, vector<int> res) {
    for (int i = 0; i < res.size() - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < store.size(); ++j) {
            if (res[i] + res[res.size() - 1] == store[j]) {
                store[j] = 0;
                flag = true;
                break;
            }
        }
        if (!flag) {
            res.clear();
            return res;
        }
    }
    if (res.size() == n) {
        return res;
    }
    for (int i = 0; i < store.size(); ++i) {
        if (store[i]) {
            res.push_back(store[i] - res[0]);
            break;
        }
    }
    return find(n, store, res);
}
