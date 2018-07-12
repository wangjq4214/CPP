#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int finding(vector<string>, vector<string>, vector<char>, int, int);

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        string temp1, temp2;
        vector<string> devide1, devide2;
        vector<char> re;
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] == '?') {
                devide1.push_back(temp1);
                devide2.push_back(temp2);
                re.push_back(str2[i]);
            } else {
                temp1 += str1[i];
                temp2 += str2[i];
            }
        }
        if (str1[str1.size() - 1] != '?') {
            devide1.push_back(temp1);
            devide2.push_back(temp2);
        }
        int x = finding(devide1, devide2, re, 0, re.size());
        cout << x << endl;
    }
}

int finding(vector<string> devide1, vector<string> devide2, vector<char> re, int i, int size) {
    if (i == devide1.size()) {
        return 0;
    }
    stringstream sstr;
    int x = -1, y = -1;
    sstr << devide1[i];
    sstr >> x;
    sstr.clear();
    sstr << devide2[i];
    sstr >> y;
    if (x < y) {
        return 0;
    } else if (x > y) {
        return pow(10, size);
    } else if (x == y) {
        int tempSize = size - 1;
        int record = re[i] - '0';
        int z = finding(devide1, devide2, re, ++i, --size);
        return (9 - record) * pow(10, tempSize) + z;
    }
}
