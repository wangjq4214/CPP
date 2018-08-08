#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, char> password, password1;
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    for (int i = 0; i < str1.size(); ++i) {
        if (!password[str1[i]] && !password1[str2[i]]) {
            password[str1[i]] = str2[i];
            password1[str2[i]] = str1[i];
        } else if (password[str1[i]] == str2[i] && password1[str2[i]] == str1[i]) {
            continue;
        } else {
            cout << "Failed";
            return 0;
        }
    }
    if (password.size() != 26) {
        cout << "Failed";
        return 0;
    }

    string temp;
    for (int i = 0; i < str3.size(); ++i) {
        temp += password[str3[i]];
    }
    cout << temp;
}
