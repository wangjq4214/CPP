#include <iostream>
#include <map>

using namespace std;

int main() {
    string str1, str2, str3;
    map<string, string> record;
    while (getline(cin, str1) && str1 != "@END@") {
        str2 = str1.substr(str1.find("["), str1.find("]") - str1.find("[") + 1);
        str3 = str1.substr(str1.find("]") + 2, str1.size() - str1.find("]"));
        record[str2] = str3;
    }
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        bool flag = false;
        for (map<string, string>::iterator iter = record.begin(); iter != record.end(); ++iter) {
            if (iter->first == str) {
                flag = true;
                cout << iter->second << endl;
                break;
            }
            if (iter->second == str) {
                flag = true;
                for (int j = 0; j < iter->first.size(); ++j) {
                    if (iter->first[j] != '[' && iter->first[j] != ']') {
                        cout << iter->first[j];
                    }
                }
                cout << endl;
            }
        }
        if (!flag) {
            cout << "what?" << endl;
        }
    }
}
