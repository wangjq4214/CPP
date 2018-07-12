#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool test(string, string, int, int, int, int);

string multiplication(const string &, int);

int main() {
    string str;
    cin >> str;

    bool flag = false;
    for (int i = 1; i <= str.size(); ++i) {
        string str1;
        str1 = multiplication(str, i);
        if (str.size() != str1.size()) {
            cout << "No";
            return 0;
        }
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < str1.size(); ++k) {
                if (str[j] == str1[k]) {
                    int count = 1;
                    flag = test(str, str1, j, k, str.size(), count);
                }
            }
        }
        if (!flag) {
            cout << "No";
            return 0;
        }
    }
    if (flag) {
        cout << "Yes";
        return 0;
    }
}

bool test(string str, string str1, int j, int k, int len, int count) {
    if (k + 1 == len) {
        k = (k + 1) - len;
    } else {
        k++;
    }
    if (count == len) {
        return true;
    }
    if (str[++j] == str1[k]) {
        count++;
        return (len, str, str1, j, k, count);
    } else {
        return false;
    }
}

string multiplication(const string &str, int x) {
    vector<string> puls;
    int count = 0;
    while (x) {
        string str1;
        for (int j = 0; j < count; ++j) {
            str1.insert(0, "0");
        }
        int y = x % 10;
        int temp1 = 0;
        for (int i = str.size() - 1; i >= 0; --i) {
            int z = y * (str[i] - '0') + temp1;
            stringstream sstr;
            if (i) {
                sstr << z % 10;
                string temp2;
                sstr >> temp2;
                str1.insert(0, temp2);
                temp1 = z / 10;
            } else {
                sstr << z;
                string temp2;
                sstr >> temp2;
                str1.insert(0, temp2);
            }
        }
        puls.push_back(str1);
        x /= 10;
        count++;
    }
    if (puls.size() == 1) {
        return puls[0];
    } else {
        string str1;
        int temp1 = 0;
        int max = puls[0].size() > puls[1].size() ? puls[0].size() : puls[1].size();
        int min = puls[0].size() > puls[1].size() ? puls[1].size() : puls[0].size();
        for (int i = 0; i < max - min; ++i) {
            if (puls[0].size() > puls[1].size()) {
                puls[1].insert(0, "0");
            } else {
                puls[0].insert(0, "0");
            }
        }
        for (int i = max - 1; i >= 0; --i) {
            int z = (puls[0][i] - '0') + (puls[1][i] - '0') + temp1;
            stringstream sstr;
            if (i) {
                sstr << z % 10;
                string temp2;
                sstr >> temp2;
                str1.insert(0, temp2);
                temp1 = z / 10;
            } else {
                sstr << z;
                string temp2;
                sstr >> temp2;
                str1.insert(0, temp2);
            }
        }
        return str1;
    }
}
