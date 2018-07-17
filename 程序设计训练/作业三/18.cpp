#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

bool test(string, string, int, int, int, int);

string multiplication(const string &, const string &);

int main() {
    string str;
    cin >> str;

    bool flag = false;
    for (int i = 1; i <= str.size(); ++i) {
        stringstream sstr;
        flag = false;
        string str1;
        sstr << i;
        sstr >> str1;
        str1 = multiplication(str, str1);
        if (str.size() != str1.size()) {
            cout << "No";
            return 0;
        }
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < str1.size(); ++k) {
                if (str[j] == str1[k]) {
                    int count = 1;
                    flag = test(str, str1, j, k, str.size(), count);
                    if (flag) {
                        break;
                    }
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

string multiplication(const string &str1, const string &str2) {
    int result[str1.size() + str2.size()];
    memset(result, 0, sizeof(result));
    for (int i = 0; i < str1.size(); ++i) {
        for (int j = 0; j < str2.size(); ++j) {
            result[i + j + 1] += (str1[i] - '0') * (str2[j] - '0');
        }
    }

    string str;
    for (int i = str1.size() + str2.size() - 1; i >= 0; --i) {
    	if (i == 0 && result[0] == 0) {
    		break;
		} 
        string temp;
        if (result[i] >= 10) {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
        stringstream sstr;
        sstr << result[i];
        sstr >> temp;
        str.insert(0, temp);
    }

    if (str.size() != str1.size() && str[0] == '0') {
        str.erase(str.begin());
    }
    return str;
}
