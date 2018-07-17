#include <iostream>
#include <vector>

using namespace std;

struct Dict {
    string str;
    int length;
};

int main() {
    vector<Dict> dictionary;
    Dict temp;
    while (cin >> temp.str && temp.str != "#") {
        temp.length = temp.str.size();
        dictionary.push_back(temp);
    }

    string str;
    int len;
    while (cin >> str && str != "#") {
        bool flag = false;
        len = str.size();
        for (int i = 0; i < dictionary.size(); ++i) {
            if (str == dictionary[i].str) {
                flag = true;
                cout << str << " is correct" << endl;
                break;
            }
        }
        if (flag) {
            continue;
        }
        cout << str << ": ";
        for (int i = 0; i < dictionary.size(); ++i) {
            if (len == dictionary[i].length) {
                int count = 0;
                for (int j = 0; j < len; ++j) {
                    if (str[j] == dictionary[i].str[j]) {
                        count++;
                    }
                }
                if (count == len - 1) {
                    cout << dictionary[i].str << " ";
                }
            } else if (len - dictionary[i].length == 1) {
                bool flag = false;
                int k = 0;
                int count = 0;
                for (int j = 0; j < len; ++j) {
                    if (str[j] != dictionary[i].str[k]) {
                        count++;
                        if (count == 2) {
                            flag = true;
                            break;
                        }
                        continue;
                    }
                    k++;
                }
                if (!flag) {
                    cout << dictionary[i].str << " ";
                }
            } else if (len - dictionary[i].length == -1) {
                bool flag = false;
                int k = 0;
                int count = 0;
                for (int j = 0; j < dictionary[i].length; ++j) {
                    if (str[k] != dictionary[i].str[j]) {
                        count++;
                        if (count == 2) {
                            flag = true;
                            break;
                        }
                        continue;
                    }
                    k++;
                }
                if (!flag) {
                    cout << dictionary[i].str << " ";
                }
            }
        }
        cout << endl;
    }
}
