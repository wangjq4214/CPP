#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    string str;
    cin >> str;
    bool flag = true;
    if (str[0] == '-') {
        str.erase(str.begin());
        flag = false;
    }
    int x;
    reverse(str.begin(), str.end());
    stringstream sstr;
    sstr << str;
    sstr >> x;
    if (flag) {
        cout << x;
    } else {
        cout << -x;
    }
}
