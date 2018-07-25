#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int count = 1;
    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            sum += (str[i] - '0') * count;
            if (count == 9) {
                break;
            }
            count++;
        }
    }

    sum = sum % 11;
    if (sum == 10) {
        if (str[str.size() - 1] == 'X') {
            cout << "Right";
        } else {
            str.replace(str.size() - 1, 1, "X");
            cout << str;
        }
    } else {
        if (str[str.size() - 1] - '0' == sum) {
            cout << "Right";
        } else {
            string temp;
            stringstream sstr;
            sstr << sum;
            sstr >> temp;
            str.replace(str.size() - 1, 1, temp);
            cout << str;
        }
    }

}
