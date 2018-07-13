#include <iostream>
#include <regex>

using namespace std;

int main() {
    string str;
    long x;
    while (cin >> str) {
        string str1, str2, temp;
        cin >> x;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '?') {
                temp += "[0-9]?";
                str1 += '9';
                str2 += '0';
            } else {
                temp += str[i];
                str1 += str[i];
                str2 += str[i];
            }
        }
        regex r("^" + temp + "$");
        long start, end;
        stringstream sstr;
        sstr << str1;
        sstr >> end;
        sstr.clear();
        sstr << str2;
        sstr >> start;
        if (end < x) {
            cout << 0 << endl;
            continue;
        }
        int sum = 0;
        for (long i = (start > x ? start : x); i <= end; ++i) {
            sstr.clear();
            sstr << i;
            sstr >> str1;
            if (i > x && regex_match(str1, r)) {
                sum++;
            }
        }
        cout << sum << endl;
    }
}
